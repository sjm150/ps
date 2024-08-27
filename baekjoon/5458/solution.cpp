#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    vector<int> dp(21 * 21 * 21 * 3 * 3 * 3 * 3, -1);
    while (t--) {
        int s[3], f[3];
        for (auto &s: s) cin >> s;
        for (auto &f: f) {
            cin >> f;
            f--;
        }
        auto key = [&](int m) { return s[0] + 21 * (s[1] + 21 * (s[2] + 21 * (m + 3 * (f[0] + 3 * (f[1] + 3 * f[2]))))); };
        function<int(int)> w = [&](int m) {
            int &d = dp[key(m)];
            if (d >= 0) return d;
            if (s[0] + s[1] + s[2] == 0) return d = (m + 2) % 3;
            d = 3 - m - f[m];
            for (int i = 0; i < 3; i++) {
                for (int j = 1; j <= s[i]; j++) {
                    s[i] -= j;
                    int r = w((m + 1) % 3);
                    s[i] += j;
                    if (r == m) return d = m;
                    else if (r == f[m]) d = f[m];
                }
            }
            return d;
        };
        w(0);
        int t[3] = {0, f[0], 3 - f[0]};
        for (int t: t) {
            for (int i = 0; i < 3; i++) {
                for (int j = 1; j <= s[i]; j++) {
                    s[i] -= j;
                    int k = key(1);
                    s[i] += j;
                    if (dp[k] == t) {
                        cout << i + 1 << ' ' << j << '\n';
                        goto done;
                    }
                }
            }
        }
        done:;
    }
}