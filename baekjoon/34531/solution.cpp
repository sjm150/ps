#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int &a: a) {
            cin >> a;
            a--;
        }
        for (int &b: b) {
            cin >> b;
            b--;
        }

        vector<int> grp(m, -1);
        function<void(int, int)> dfs = [&](int cur, int g) {
            grp[cur] = g;
            if (grp[b[cur]] < 0) dfs(b[cur], g);
        };
        int gsz = 0;
        for (int i = 0; i < m; i++) {
            if (grp[i] < 0) dfs(i, gsz++);
        }

        vector<vector<int>> gv(gsz);
        for (int i = 0; i < m; i++) gv[grp[i]].push_back(i);

        int pre = -1;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            auto &v = gv[grp[a[i]]];
            auto it = lower_bound(v.begin(), v.end(), pre);
            if (it == v.end()) {
                ok = false;
                break;
            }
            pre = *it;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}