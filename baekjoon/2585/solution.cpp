#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int f(pi &a, pi &b) {
    int dsq = ((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
    int l = 1, r = 1501;
    while (l < r) {
        int m = (l + r) / 2;
        if (m * m * 100 < dsq) l = m + 1;
        else r = m;
    }
    return r;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<pi> crd(n + 2);
    crd[0] = {0, 0};
    crd[n + 1] = {10000, 10000};
    for (int i = 1; i <= n; i++) cin >> crd[i].first >> crd[i].second;

    vector<vector<pi>> edges(n + 2);
    for (int i = 0; i <= n + 1; i++) {
        for (int j = i + 1; j <= n + 1; j++) {
            int d = f(crd[i], crd[j]);
            edges[i].emplace_back(d, j);
            edges[j].emplace_back(d, i);
        }
        sort(edges[i].begin(), edges[i].end());
    }

    int l = 1, r = 1501;
    vector<int> dst(n + 2);
    queue<int> q;

    while (l < r) {
        int m = (l + r) / 2;
        fill(dst.begin(), dst.end(), -1);
        dst[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto [d, nxt]: edges[cur]) {
                if (d > m) break;
                if (dst[nxt] >= 0) continue;
                dst[nxt] = dst[cur] + 1;
                q.push(nxt);
            }
        }

        if (0 < dst[n + 1] && dst[n + 1] <= k + 1) r = m;
        else l = m + 1;
    }

    cout << r << '\n';
}