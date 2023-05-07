#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct Edge {
    int to;
    int weight;
} edge_t;

int solution(int n, vector<vector<int>> costs) {
    vector<vector<edge_t>> edges(n);
    for (auto& info: costs) {
        int v1 = info[0], v2 = info[1], cost = info[2];
        edges[v1].push_back(Edge {v2, cost});
        edges[v2].push_back(Edge {v1, cost});
    }
    
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>> pq;
    for (auto& edge: edges[0]) pq.emplace(-edge.weight, edge.to);
    visited[0] = true;
    
    int total_cost = 0;
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        
        if (!visited[curr]) {
            total_cost += cost;
            for (auto& edge: edges[curr]) {
                int next = edge.to;
                if (!visited[next]) pq.emplace(-edge.weight, next);
            }
            visited[curr] = true;
        }
    }
    
    return total_cost;
}