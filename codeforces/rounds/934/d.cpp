#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        string s; cin >> s;

        set<int> nrep, nalt;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] != s[i + 1]) nrep.insert(i + 1);
            if (i < n - 2 && s[i] != s[i + 2]) nalt.insert(i + 2);
        }

        string sp = "|";
        for (char c: s) {
            sp.push_back(c);
            sp.push_back('|');
        }
        int sz = sp.size();
        vector<int> len(sz);

        int m = 0, r = 0;
        while (m < sz) {
            while (m - r - 1 >= 0 && m + r + 1 < sz && sp[m - r - 1] == sp[m + r + 1]) r++;
            len[m] = r;

            int pm = m, pr = r;
            for (m++, r = 0; m < pm + pr; m++) {
                int mm = 2 * pm - m;
                int lim = pm + pr - m;
                if (len[mm] == lim) {
                    r = lim;
                    break;
                } else {
                    len[m] = min(len[mm], lim);
                }
            }
        }

        while (q--) {
            int l, r; cin >> l >> r;
            l--, r--;
            int t = r - l + 1;
            auto it = nrep.upper_bound(l);
            if (it == nrep.end() || r < *it) cout << 0 << '\n';
            else if ((it = nalt.upper_bound(l + 1)) == nalt.end() || r < *it) cout << ll(t / 2) * (t / 2 + 1) << '\n';
            else if (len[l + r + 1] >= t) cout << t * ll(t - 1) / 2 - 1 << '\n';
            else cout << t * ll(t + 1) / 2 - 1 << '\n';
        }
    }
}