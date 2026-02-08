#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<string> s(k);
        for (auto &s: s) cin >> s;

        vector<vector<bool>> exst(n, vector<bool>(26, false));
        for (auto &s: s) {
            for (int i = 0; i < n; i++) exst[i][s[i] - 'a'] = true;
        }

        auto chk = [&](int d) {
            for (int i = 0; i < d; i++) {
                bool poss = false;
                for (int c = 0; c < 26; c++) {
                    bool all = true;
                    for (int j = i; j < n; j += d) {
                        if (!exst[j][c]) {
                            all = false;
                            break;
                        }
                    }
                    if (all) {
                        poss = true;
                        break;
                    }
                }
                if (!poss) return false;
            }
            return true;
        };

        auto getd = [&]() {
            int d;
            for (d = 1; d * d <= n; d++) {
                if (n % d == 0 && chk(d)) return d;
            }
            for (; d; d--) {
                if (n % d == 0 && chk(n / d)) return n / d;
            }
            return n;
        };

        int d = getd();
        string ans(n, ' ');
        for (int i = 0; i < d; i++) {
            for (int c = 0; c < 26; c++) {
                bool all = true;
                for (int j = i; j < n; j += d) {
                    if (!exst[j][c]) {
                        all = false;
                        break;
                    }
                }
                if (all) {
                    for (int j = i; j < n; j += d) ans[j] = c + 'a';
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
}