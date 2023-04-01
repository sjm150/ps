#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct edge_t { int to; int weight; };
vector<vector<edge_t>> edges;
vector<int> fires;
vector<int> stations;

vector<int> multi_ori_dijkstra(vector<int>& origins);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        int v, e, n, m;
        cin >> v >> e >> n >> m;

        edges = vector<vector<edge_t>>(e);
        for (int i = 0; i < e; i++) {
            int a, b, t;
            cin >> a >> b >> t;
            edges[a].push_back(edge_t { b, t });
            edges[b].push_back(edge_t { a, t });
        }

        fires = vector<int>(n);
        stations = vector<int>(m);
        for (int i = 0; i < n; i++) cin >> fires[i];
        for (int i = 0; i < m; i++) cin >> stations[i];

        vector<int> dist = multi_ori_dijkstra(stations);
        int sum = 0;
        for (int fire: fires) sum += dist[fire];
        cout << sum << endl;
    }
}

vector<int> multi_ori_dijkstra(vector<int>& origins) {
    vector<int> dist(edges.size(), INT32_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int origin: origins) {
        dist[origin] = 0;
        pq.emplace(origin, 0);
    }

    while (!pq.empty()) {
        int curr = pq.top().first;
        int curr_dist = pq.top().second;
        pq.pop();
        if (curr_dist > dist[curr]) continue;

        for (auto& edge: edges[curr]) {
            int next = edge.to;
            int next_dist = curr_dist + edge.weight;
            if (next_dist < dist[next]) {
                dist[next] = next_dist;
                pq.emplace(next, next_dist);
            }
        }
    }

    return dist;
}