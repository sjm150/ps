#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

typedef struct Djset {
    vector<int> p, r;
    Djset(int n): p(n), r(n, 0) { iota(p.begin(), p.end(), 0); }
    int find(int u) {
        if (p[u] == u) return u;
        return p[u] = find(p[u]);
    }
    bool uni(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (r[u] < r[v]) swap(u, v);
        p[v] = u;
        if (r[u] == r[v]) r[u]++;
        return true;
    }
} djs_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> edges(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        set<int> rem;
        for (int i = 1; i <= n; i++) rem.insert(i);
        vector<int> mn(n + 1), mx(n + 1);
        mn[0] = n + 1, mx[0] = 0;
        map<pi, pi> mm;
        function<void(int, int)> mdfs = [&](int pre, int cur) {
            int mnc = cur, mxc = cur;
            mn[cur] = min(cur, mn[pre]), mx[cur] = max(cur, mx[pre]);
            rem.erase(rem.find(cur));
            for (int nxt: edges[cur]) {
                if (nxt == pre) continue;
                mdfs(cur, nxt);
                mm.emplace(pi(cur, nxt), pi(mn[nxt], mx[nxt]));
                mn[cur] = min(mn[cur], mn[nxt]);
                mx[cur] = max(mx[cur], mx[nxt]);
                mnc = min(mnc, mn[nxt]);
                mxc = max(mxc, mx[nxt]);
            }
            int mnp = mn[pre], mxp = mx[pre];
            if (!rem.empty()) {
                mnp = min(mnp, *rem.begin());
                mxp = max(mxp, *prev(rem.end()));
            }
            mm.emplace(pi(cur, pre), pi(mnp, mxp));
            mn[cur] = mnc, mx[cur] = mxc;
        };
        mdfs(0, 1);

        vector<int> in(n + 1), ou(n + 1);
        int iidx = 0, oidx = 0;
        function<void(int, int)> dfs = [&](int pre, int cur) {
            in[cur] = iidx++;
            for (int nxt: edges[cur]) {
                if (nxt == pre) continue;
                dfs(cur, nxt);
            }
            ou[cur] = oidx++;
        };
        dfs(0, 1);

        vector<int> didx(n + 1);
        for (int i = 1; i <= n; i++) {
            int sz = edges[i].size();
            djs_t djs(sz);
            vector<pi> ins;
            for (int j = 0; j < sz; j++) {
                didx[edges[i][j]] = j;
                ins.emplace_back(in[edges[i][j]], edges[i][j]);
            }
            sort(ins.begin(), ins.end());

            bool crsd = i == 1 || i == n;
            vector<tuple<int, int, int>> cnds;
            for (int j: edges[i]) {
                auto &[mn, mx] = mm[pi(i, j)];
                if (mn < i && i < mx) crsd = true;
                if (mn != 1 && mn != i + 1) cnds.emplace_back(j, mn, mn - 1);
                if (mx != n && mx != i - 1) cnds.emplace_back(j, mx, mx + 1);
            }

            vector<pi> ans;
            if (!crsd) ans.emplace_back(i - 1, i + 1);
            for (auto &[j, u, v]: cnds) {
                auto it = upper_bound(ins.begin(), ins.end(), pi(in[v], n + 1));
                int t;
                if (it != ins.begin() && ou[prev(it)->second] >= ou[v]) t = prev(it)->second;
                else t = ins.begin()->second;
                if (djs.uni(didx[j], didx[t])) ans.emplace_back(u, v);
            }

            cout << ans.size() + !crsd << ' ' << ans.size() << '\n';
            for (auto &[u, v]: ans) cout << u << ' ' << v << '\n';
            cout << '\n';
        }
    }
}