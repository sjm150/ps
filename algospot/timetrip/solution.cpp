#include <iostream>
#include <vector>

#define INF 123456789
#define STD 100000000

using namespace std;

struct edge_t { int to; int weight; };

vector<int> bellman_ford(vector<vector<edge_t>>& edges);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        int v, w;
        cin >> v >> w;
        vector<vector<edge_t>> edges(v);
        vector<vector<edge_t>> neg_edges(v);
        for (int i = 0; i < w; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            edges[a].push_back(edge_t {b, d});
            neg_edges[a].push_back(edge_t {b, -d});
        }

        int past = bellman_ford(edges)[1];
        if (past > STD) {
            cout << "UNREACHABLE\n";
            continue;
        }
        int future = bellman_ford(neg_edges)[1];

        if (past == -STD) cout << "INFINITY";
        else cout << past;
        cout << " ";
        if (future == -STD) cout << "INFINITY";
        else cout << -future;
        cout << endl;
    }
}

bool is_reachable(int from, int to, vector<vector<edge_t>>& edges) {
    int v = edges.size();
    vector<bool> visited(v, false);
    vector<int> stack;
    stack.push_back(from);
    visited[from] = true;

    while (!stack.empty()) {
        int curr = stack.back();
        stack.pop_back();

        for (auto& edge: edges[curr]) {
            int next = edge.to;
            if (next == to) return true;

            if (!visited[next]) {
                stack.push_back(next);
                visited[next] = true;
            }
        }
    }

    return false;
}

vector<int> bellman_ford(vector<vector<edge_t>>& edges) {
    int v = edges.size();
    vector<int> dist(v, INF);
    dist[0] = 0;

    for (int i = 0; i < v - 1; i++) {
        bool relaxed = false;
        for (int curr = 0; curr < v; curr++) {
            for (auto& edge: edges[curr]) {
                if (dist[edge.to] > dist[curr] + edge.weight) {
                    dist[edge.to] = dist[curr] + edge.weight;
                    relaxed = true;
                }
            }
        }

        if (!relaxed) break;
    }

    vector<int> relaxed;
    for (int curr = 0; curr < v; curr++) {
        for (auto& edge: edges[curr]) {
            if (dist[edge.to] > dist[curr] + edge.weight) relaxed.push_back(edge.to);
        }
    }
    for (int r: relaxed) {
        if (is_reachable(0, r, edges) && is_reachable(r, 1, edges)) {
            dist[1] = -STD;
            break;
        }
    }

    return dist;
}