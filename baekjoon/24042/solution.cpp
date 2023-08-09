#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pi;
const ll inf = 1e12;

vector<pi> edges[100001];
ll tm[100001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        edges[a].emplace_back(i, b);
        edges[b].emplace_back(i, a);
    }
    fill(tm, tm + n + 1, inf);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    tm[1] = 0;
    pq.emplace(0, 1);
    while (!pq.empty()) {
        auto [t, cur] = pq.top(); pq.pop();
        if (t != tm[cur]) continue;
        int p = t / m, r = t % m;
        for (auto [i, nxt]: edges[cur]) {
            ll nxtt = ll(m) * (r <= i ? p : p + 1) + i + 1;
            if (tm[nxt] > nxtt) {
                tm[nxt] = nxtt;
                pq.emplace(nxtt, nxt);
            }
        }
    }
    cout << tm[n] << '\n';
}