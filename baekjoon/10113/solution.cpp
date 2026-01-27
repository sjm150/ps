#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef unsigned long long ull;
    typedef struct Fwtree {
        vector<int> val;
        Fwtree(int n): val(n + 1, 0) {}
        void add(int i) {
            i++;
            while (i < val.size()) {
                val[i]++;
                i += i & -i;
            }
        }
        int get(int i) {
            i++;
            int ret = 0;
            while (i) {
                ret += val[i];
                i &= i - 1;
            }
            return ret;
        }
    } fwt_t;

    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<pair<int, int>> rc(m);
    for (int i = 0; i < m; i++) {
        int r;
        char c;
        cin >> r >> c;
        rc[i] = {r - 1, c - 'A'};
    }

    vector<vector<bool>> ext(n, vector<bool>(6, true));
    fwt_t fwt(n);
    vector<int> fr(m), bk(m);
    for (int i = 0; i < m; i++) {
        auto [r, c] = rc[i];
        ext[r][c] = false;
        if (c == 2 || c == 3) fwt.add(r);
        fr[i] = 2 * (r + 1) - fwt.get(r) + ((c == 0 && ext[r][1]) || (c == 5 && ext[r][4]));
        bk[i] = 2 * (n - r) - fwt.get(n - 1) + fwt.get(r - 1) + ((c == 0 && ext[r][1]) || (c == 5 && ext[r][4]));
    }

    vector<int> ord(m);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return fr[i] - bk[i] < fr[j] - bk[j]; });
    vector<ull> pref(m + 1), preb(m + 1);
    pref[0] = preb[0] = 0;
    for (int i = 0; i < m; i++) {
        pref[i + 1] = pref[i] + fr[ord[i]];
        preb[i + 1] = preb[i] + bk[ord[i]];
    }

    ull ans = 1e19;
    for (int i = 0; i <= m; i++) ans = min(ans, a * (pref[i] + preb[m] - preb[i]) + b * (ull(i) * (i - 1) / 2 + ull(m - i) * (m - i - 1) / 2));
    cout << ans << '\n';
}