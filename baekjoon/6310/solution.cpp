#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (int h = 1; ; h++) {
        int n; cin >> n;
        if (!n) break;
        cout << "Heap " << h << '\n';

        vector<array<int, 4>> sld(n);
        for (auto &s: sld) cin >> s[0] >> s[1] >> s[2] >> s[3];
        vector<set<int>> num(n), on(n);
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            for (int j = 0; j < n; j++) {
                if (sld[j][0] < x && x < sld[j][1] && sld[j][2] < y && y < sld[j][3]) {
                    num[j].insert(i);
                    on[i].insert(j);
                }
            }
        }

        vector<int> ans(n, -1);
        vector<bool> schk(n, false), nchk(n, false);
        for (int i = 0; i < n; i++) {
            int m = -1;
            for (int j = 0; j < n; j++) {
                if (schk[j]) continue;
                if (num[j].size() == 1) {
                    m = j;
                    ans[m] = *num[m].begin();
                    break;
                }
            }
            if (m < 0) {
                for (int j = 0; j < n; j++) {
                    if (nchk[j]) continue;
                    if (on[j].size() == 1) {
                        m = *on[j].begin();
                        ans[m] = j;
                        break;
                    }
                }
                if (m < 0) break;
            }
            schk[m] = nchk[ans[m]] = true;
            for (auto &num: num) num.erase(ans[m]);
            for (auto &on: on) on.erase(m);
        }

        bool prnt = false;
        for (int i = 0; i < n; i++) {
            if (ans[i] >= 0) {
                cout << '(' << char(i + 'A') << ',' << ans[i] + 1 << ") ";
                prnt = true;
            }
        }
        if (!prnt) cout << "none";
        cout << "\n\n";
    }
}