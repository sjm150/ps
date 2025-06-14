#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> p(n);
        vector<int> d(n);
        for (ll &p: p) cin >> p;
        for (int &d: d) cin >> d;

        int sz = n * 2;
        vector<vector<int>> edges(sz + 1);
        for (int i = 0; i < n; i++) {
            int j = i - 1;
            for (; j >= 0; j--) {
                if ((p[i] - p[j]) % k == (d[j] - d[i] + k) % k) {
                    edges[j].push_back(i + n);
                    break;
                }
            }
            if (j < 0) edges[sz].push_back(i + n);
            j = i + 1;
            for (; j < n; j++) {
                if ((p[j] - p[i]) % k == (d[j] - d[i] + k) % k) {
                    edges[j + n].push_back(i);
                    break;
                }
            }
            if (j >= n) edges[sz].push_back(i);
        }

        vector<bool> vst(sz, false);
        function<void(int)> dfs = [&](int cur) {
            vst[cur] = true;
            for (int nxt: edges[cur]) {
                if (!vst[nxt]) dfs(nxt);
            }
        };
        dfs(sz);

        int q;
        cin >> q;
        while (q--) {
            ll a;
            cin >> a;

            int idx = lower_bound(p.begin(), p.end(), a) - p.begin();
            bool ok = true;
            for (int i = idx; i < n; i++) {
                if ((p[i] - a) % k == d[i]) {
                    if (!vst[i + n]) ok = false;
                    break;
                }
            }
            cout << (ok ? "YES\n" : "NO\n");
        }
    }
}