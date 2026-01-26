#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int n, m;
    cin >> n >> m;
    vector<int> l(n);
    for (int &l: l) cin >> l;
    vector<vector<int>> edges(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<bool> vst(n, false), odd(n);
    bool ok;
    int cnt[2];
    function<void(int, bool)> dfs = [&](int cur, bool o) {
        vst[cur] = true;
        odd[cur] = o;
        cnt[o]++;
        for (int nxt: edges[cur]) {
            if (vst[nxt]) {
                if (odd[cur] == odd[nxt]) ok = false;
            } else {
                dfs(nxt, !o);
            }
        }
    };

    ll ans = 0;
    auto xc2 = [](ll x) { return x * (x - 1) / 2; };
    for (int i = 0; i < n; i++) {
        if (vst[i]) continue;
        ok = true;
        cnt[0] = cnt[1] = 0;
        dfs(i, false);
        ans += ok ? xc2(cnt[0]) + xc2(cnt[1]) : xc2(cnt[0] + cnt[1]);
    }
    cout << ans << '\n';
}