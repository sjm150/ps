#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> edges(n);
    for (auto& e: edge) {
        int from = e[0], to = e[1];
        edges[from - 1].push_back(to - 1);
        edges[to - 1].push_back(from - 1);
    }
    
    vector<int> dist(n, -1);
    queue<int> q;
    int max_dist = 0;
    dist[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int curr = q.front();
        int curr_dist = dist[curr];
        q.pop();
        
        for (int next: edges[curr]) {
            int& next_dist = dist[next];
            if (next_dist < 0) {
                next_dist = curr_dist + 1;
                max_dist = max(max_dist, next_dist);
                q.push(next);
            }
        }
    }
    
    int count = 0;
    for (int d: dist) {
        if (d == max_dist) count++;
    }
    return count;
}