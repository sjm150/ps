#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> p(m);
    for (auto &p: p) {
        int o; cin >> o;
        p.resize(o);
        for (int &p: p) cin >> p;
    }

    int ans = m + 1;
    vector<bool> sol(n);
    for (int i = 1; i < (1 << m); i++) {
        fill(sol.begin(), sol.end(), false);
        int cnt = 0;
        for (int b = 0, d = 1; b <= i; b++, d *= 2) {
            if (d & i) {
                cnt++;
                for (int p: p[b]) sol[p - 1] = true;
            }
        }
        bool poss = true;
        for (bool s: sol) {
            if (!s) {
                poss = false;
                break;
            }
        }
        if (poss) ans = min(ans, cnt);
    }

    if (ans <= m) cout << ans << '\n';
    else cout << -1 << '\n';
}