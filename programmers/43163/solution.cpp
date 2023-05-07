#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int string_diff(string& a, string& b) {
    int len = a.length();
    int diff = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) diff++;
    }
    return diff;
}

int solution(string begin, string target, vector<string> words) {
    int n = words.size();
    auto it = find(words.begin(), words.end(), target);
    if (it == words.end()) return 0;
    int target_idx = it - words.begin();

    vector<vector<int>> edges(n + 1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (string_diff(words[i], words[j]) == 1) {
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (string_diff(begin, words[i]) == 1) {
            edges[n].push_back(i);
        }
    }
    
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int next: edges[curr]) {
            if (dist[next] < 0) {
                q.push(next);
                dist[next] = dist[curr] + 1;
            }
        }
    }
    
    return dist[target_idx];
}