#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct edge {
    int to;
    double weight;
};

int n, m;
vector<vector<edge>> edges;

vector<double> mul_dijkstra(int src);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout << setprecision(10);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        cin >> n >> m;
        edges.clear();
        edges = vector<vector<edge>>(n, vector<edge>());
        for (int i = 0; i < m; i++) {
            int v, u;
            double weight;
            cin >> v >> u >> weight;
            edges[v].push_back(edge {u, weight});
            edges[u].push_back(edge {v, weight});
        }

        cout << mul_dijkstra(0)[n - 1] << endl;
    }
}

const double INF = pow(double(3), 10000);

vector<double> mul_dijkstra(int src) {
    vector<double> noise = vector<double>(n, INFINITY);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

    noise[src] = 1;
    pq.emplace(1, src);
    while (!pq.empty()) {
        int curr = pq.top().second;
        double curr_noise = pq.top().first;
        pq.pop();
        if (curr_noise > noise[curr]) continue;

        for (auto& e: edges[curr]) {
            double new_noise = curr_noise * e.weight;
            if (new_noise < noise[e.to]) {
                noise[e.to] = new_noise;
                pq.emplace(new_noise, e.to);
            }
        }
    }

    return noise;
}