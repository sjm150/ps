#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;
const int inf = 123456789;

vector<pi> edges[1001];
int dst[1000][1001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    int s, e; cin >> s >> e;
    while (m--) {
        int a, b, w; cin >> a >> b >> w;
        edges[a].emplace_back(w, b);
        edges[b].emplace_back(w, a);
    }
    queue<ti> q;
    for (int i = 0; i < n; i++) fill(dst[i], dst[i] + n + 1, inf);
    dst[0][s] = 0;
    q.emplace(0, 0, s);
    while (!q.empty()) {
        auto [d, cnt, cur] = q.front(); q.pop();
        if (d != dst[cnt][cur]) continue;
        for (auto [w, nxt]: edges[cur]) {
            if (cnt < n - 1 && dst[cnt + 1][nxt] > d + w) {
                dst[cnt + 1][nxt] = d + w;
                q.emplace(d + w, cnt + 1, nxt);
            }
        }
    }
    int mind = inf, minc = n;
    for (int i = 0; i < n; i++) {
        if (mind > dst[i][e]) {
            mind = dst[i][e];
            minc = i;
        }
    }
    vector<pi> ans;
    for (int i = minc; i >= 0; i--) {
        if (dst[i][e] < inf) ans.emplace_back(dst[i][e], i);
    }
    int idx = 0;
    cout << ans[idx].first << '\n';
    while (k--) {
        int p; cin >> p;
        mind = inf, minc = n;
        for (int i = idx; i < ans.size(); i++) {
            ans[i].first += p * ans[i].second;
            if (mind > ans[i].first) {
                mind = ans[i].first;
                minc = i;
            }
        }
        idx = minc;
        cout << ans[idx].first << '\n';
    }
}