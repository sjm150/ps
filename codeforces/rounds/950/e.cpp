#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
        for (auto &a: a) {
            for (int &a: a) cin >> a;
        }
        for (auto &b: b) {
            for (int &b: b) cin >> b;
        }

        vector<vector<int>> row(n), col(m);
        vector<pair<int, int>> acrd(n * m + 1), bcrd(n * m + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cur = a[i][j];
                row[i].push_back(cur);
                col[j].push_back(cur);
                acrd[cur] = {i, j};
                bcrd[b[i][j]] = {i, j};
            }
        }
        for (auto &r: row) sort(r.begin(), r.end());
        for (auto &c: col) sort(c.begin(), c.end());

        vector<bool> chk(n * m + 1, false);
        bool poss = true;
        for (int k = 1; k <= n * m; k++) {
            if (chk[k]) continue;
            int ar = acrd[k].first;
            int br = bcrd[k].first;
            for (int j = 0; j < m; j++) {
                if (!binary_search(row[ar].begin(), row[ar].end(), b[br][j])) {
                    poss = false;
                    break;
                }
                chk[b[br][j]] = true;
            }
            if (!poss) break;
        }
        if (!poss) {
            cout << "NO\n";
            continue;
        }

        fill(chk.begin(), chk.end(), false);
        for (int k = 1; k <= n * m; k++) {
            if (chk[k]) continue;
            int ac = acrd[k].second;
            int bc = bcrd[k].second;
            for (int i = 0; i < n; i++) {
                if (!binary_search(col[ac].begin(), col[ac].end(), b[i][bc])) {
                    poss = false;
                    break;
                }
                chk[b[i][bc]] = true;
            }
            if (!poss) break;
        }
        if (!poss) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
    }
}