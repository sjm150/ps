#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--;
    }

    vector<vector<int>> cyc;
    vector<bool> inc(n, false);
    vector<int> vst(n, -1);
    function<void(int, int)> dfs = [&](int cur, int v) {
        vst[cur] = v;
        if (vst[a[cur]] == v) {
            vector<int> c(1, cur);
            inc[cur] = true;
            while (a[c.back()] != cur) {
                c.push_back(a[c.back()]);
                inc[c.back()] = true;
            }
            cyc.push_back(c);
        } else if (vst[a[cur]] < 0) {
            dfs(a[cur], v);
        }
    };
    int v = 0;
    for (int i = 0; i < n; i++) {
        if (vst[i] < 0) dfs(i, v++);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (!inc[i]) ans += ll(b[i]) * max(c[a[i]], d[a[i]]);
    }
    for (auto &cyc: cyc) {
        int sz = cyc.size();
        vector<vector<ll>> p(sz, vector<ll>(2, 0));
        p[0][1] = -1e18;
        for (int i = 1; i < sz; i++) {
            for (int j = 0; j < 2; j++) p[i][j] = max(p[i - 1][j] + ll(b[cyc[i - 1]]) * c[cyc[i]], p[i - 1][1 - j] + ll(b[cyc[i - 1]]) * d[cyc[i]]);
        }
        ans += max(p[sz - 1][0] + ll(b[cyc[sz - 1]]) * c[cyc[0]], p[sz - 1][1] + ll(b[cyc[sz - 1]]) * d[cyc[0]]);
    }
    cout << ans << '\n';
}