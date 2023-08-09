#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pi;
typedef tuple<ll, int, int> ti;
const ll inf = 1e11;

vector<pi> edges[10001];
ll tm[21][10001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        edges[u].emplace_back(w, v);
        edges[v].emplace_back(w, u);
    }
    priority_queue<ti, vector<ti>, greater<ti>> pq;
    for (int i = 0; i <= k; i++){
        fill(tm[i], tm[i] + n + 1, inf);
        tm[i][1] = 0;
    }
    pq.emplace(0, 0, 1);
    while (!pq.empty()) {
        auto [t, cnt, cur] = pq.top(); pq.pop();
        if (t != tm[cnt][cur]) continue;
        for (auto [w, nxt]: edges[cur]) {
            if (tm[cnt][nxt] > t + w) {
                tm[cnt][nxt] = t + w;
                pq.emplace(t + w, cnt, nxt);
            }
            if (cnt < k && tm[cnt + 1][nxt] > t) {
                tm[cnt + 1][nxt] = t;
                pq.emplace(t, cnt + 1, nxt);
            }
        }
    }
    ll mint = inf;
    for (int i = 0; i <= k; i++) mint = min(mint, tm[i][n]);
    cout << mint << '\n';
}