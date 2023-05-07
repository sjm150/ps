#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void dfs(int curr, vector<vector<int>>& edges, vector<int>& order) {
    while (!edges[curr].empty()) {
        int next = edges[curr].back();
        edges[curr].pop_back();
        dfs(next, edges, order);
    }
    
    order.push_back(curr);
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end(), [](vector<string>& a, vector<string>& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        else return a[0] > b[0];
    });
    
    vector<string> names;
    unordered_map<string, int> idx;
    vector<vector<int>> edges;
    for (auto& ticket: tickets) {
        string& from = ticket[0], to = ticket[1];
        
        int from_idx, to_idx;
        if (auto it = idx.find(from); it != idx.end()) {
            from_idx = it->second;
        } else {
            from_idx = idx.emplace(from, edges.size()).first->second;
            edges.push_back(vector<int>());
            names.push_back(from);
        }
        if (auto it = idx.find(to); it != idx.end()) {
            to_idx = it->second;
        } else {
            to_idx = idx.emplace(to, edges.size()).first->second;
            edges.push_back(vector<int>());
            names.push_back(to);
        }
        
        edges[from_idx].push_back(to_idx);
    }

    vector<int> order;
    dfs(idx["ICN"], edges, order);
    vector<string> result;
    for (int i = order.size() - 1; i >= 0; i--) result.push_back(names[order[i]]);
    
    return result;
}