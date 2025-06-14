#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const ll inf = 1e18;
    int t; cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> p(n), d(n);
        for (ll &p: p) cin >> p;
        for (ll &d: d) cin >> d;

        vector<ll> sum(n), dif(n);
        for (int i = 0; i < n; i++) {
            sum[i] = (p[i] + d[i]) % k;
            dif[i] = ((d[i] - p[i]) % k + k) % k;
        }

        vector<pair<ll, int>> si = {make_pair(ll(-1), -1), make_pair(inf, -1)}, di = si;
        for (int i = 0; i < n; i++) {
            si.emplace_back(sum[i], i);
            di.emplace_back(dif[i], i);
        }
        sort(si.begin(), si.end());
        sort(di.begin(), di.end());

        int sz = n * 2;
        vector<vector<int>> edges(sz + 1);
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(si.begin(), si.end(), make_pair(sum[i], i));
            if (prev(it)->first != sum[i]) edges[sz].push_back(i + n);
            else edges[prev(it)->second].push_back(i + n);

            it = upper_bound(di.begin(), di.end(), make_pair(dif[i], i));
            if (it->first != dif[i]) edges[sz].push_back(i);
            else edges[it->second + n].push_back(i);
        }

        vector<bool> vst(sz + 1, false);
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
            ll df = (-a % k + k) % k;
            auto it = lower_bound(di.begin(), di.end(), make_pair(df, idx));
            cout << (idx < n && it->first == df && !vst[it->second + n] ? "NO\n" : "YES\n");
        }
    }
}