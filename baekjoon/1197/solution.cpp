#include <iostream>
#include <queue>
using namespace std;

vector<pair<int, int>> edges[10001];
bool used[10001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int v, e; cin >> v >> e;
    while (e--) {
        int a, b, c; cin >> a >> b >> c;
        edges[a].emplace_back(c, b);
        edges[b].emplace_back(c, a);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    used[1] = true;
    for (auto e: edges[1]) {
        if (!used[e.second]) pq.push(e);
    }
    int sum = 0;
    while (!pq.empty()) {
        auto [w, v] = pq.top(); pq.pop();
        if (used[v]) continue;
        used[v] = true;
        sum += w;
        for (auto e: edges[v]) pq.push(e);
    }
    cout << sum << '\n';
}