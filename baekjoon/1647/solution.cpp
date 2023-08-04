#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pi;

vector<pi> edges[100001];
bool con[100001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        edges[a].emplace_back(c, b);
        edges[b].emplace_back(c, a);
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    con[1] = true;
    for (auto& e: edges[1]) pq.emplace(e);
    int sum = 0, maxc = 0;
    while (!pq.empty()) {
        auto [c, v] = pq.top(); pq.pop();
        if (con[v]) continue;
        con[v] = true;
        sum += c;
        maxc = max(maxc, c);
        for (auto& e: edges[v]) {
            if (!con[e.second]) pq.emplace(e);
        }
    }
    cout << sum - maxc << '\n';
}