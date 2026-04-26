#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef bitset<256> bs;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b = a;
    for (auto &a: a) {
        for (int &a: a) cin >> a;
    }
    for (auto &b: b) {
        for (int &b: b) cin >> b;
    }

    vector<bs> ab(m), bb(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) ab[j][i] = a[i][j], bb[j][i] = b[i][j];
    }

    bool ok = true;
    vector<vector<int>> ans;
    vector<bool> swpd(m, false);
    for (int i = 0; i < n; i++) {
        int ac = 0, bc = 0;
        for (int j = 0; j < m; j++) ac += ab[j][i], bc += bb[j][i];
        if (ac != bc) {
            if (ac == m - bc) {
                ans.push_back({0, i + 1});
                for (int j = 0; j < m; j++) ab[j][i].flip();
            } else {
                ok = false;
                break;
            }
        }

        bool poss = true;
        for (int j = 0; j < m; j++) {
            if (ab[j][i] != bb[j][i] && swpd[j]) {
                poss = false;
                break;
            }
        }
        if (!poss) {
            if (ac == bc && ac == m - bc) {
                ans.push_back({0, i + 1});
                for (int j = 0; j < m; j++) ab[j][i].flip();
            }
            poss = true;
            for (int j = 0; j < m; j++) {
                if (ab[j][i] != bb[j][i] && swpd[j]) {
                    poss = false;
                    break;
                }
            }
            if (!poss) {
                ok = false;
                break;
            }
        }

        for (int j = 0; j < m; j++) {
            if (ab[j][i] == bb[j][i]) continue;
            for (int k = j + 1; k < m; k++) {
                if (ab[k][i] == bb[k][i] || ab[k][i] != bb[j][i]) continue;
                swap(ab[j], ab[k]);
                swpd[j] = swpd[k] = true;
                ans.push_back({1, j + 1, k + 1});
                break;
            }
        }
    }

    if (ok) {
        cout << ans.size() << '\n';
        for (auto &a: ans) {
            for (int a: a) cout << a << ' ';
            cout << '\n';
        }
    } else {
        cout << -1 << '\n';
    }
}