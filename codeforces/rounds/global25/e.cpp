#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();

        string sp = "|";
        for (char c: s) {
            sp += c;
            sp += '|';
        }

        int i = 0, r = 0;
        int sz = sp.size();
        vector<int> pr(sz);
        while (i < sz) {
            while (i - r - 1 >= 0 && i + r + 1 < sz && sp[i - r - 1] == sp[i + r + 1]) r++;
            pr[i] = r;

            int oli = i, olr = r;
            i++, r = 0;
            while (i <= oli + olr) {
                int mi = oli * 2 - i;
                int lim = oli + olr - i;
                if (pr[mi] < lim) {
                    pr[i] = pr[mi];
                    i++;
                } else if (pr[mi] > lim) {
                    pr[i] = lim;
                    i++;
                } else {
                    r = lim;
                    break;
                }
            }
        }

        if (pr[n] < n) {
            cout << "YES\n";
            cout << 1 << '\n';
            cout << s << '\n';
            continue;
        }

        bool sme = true, swe = true;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[0]) {
                sme = false;
                break;
            }
        }
        for (int i = 2; i < n; i++) {
            if (s[i] != s[i & 1]) {
                swe = false;
                break;
            }
        }

        if (sme || swe) {
            cout << "NO\n";
            continue;
        }

        bool prnt = false;
        for (int i = 1; i < n / 2; i++) {
            if (pr[i + 1] < i && pr[i + 1 + n] < n - i - 1) {
                cout << "YES\n";
                cout << 2 << '\n';
                for (int j = 0; j <= i; j++) cout << s[j];
                cout << ' ';
                for (int j = i + 1; j < n; j++) cout << s[j];
                cout << '\n';
                prnt = true;
                break;
            }
        }
        if (!prnt) cout << "NO\n";
    }
}