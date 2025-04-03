#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string s, t; cin >> s >> t;
        int n = s.size();
        vector<int> c(26, -1);
        for (int i = 0; i < n; i++) c[s[i] - 'A'] = t[i] - 'A';
        bool ok = true;
        for (char t: t) {
            if (c[t - 'A'] < 0) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "mjau\n";
            continue;
        }
        vector<bool> vst(26, false);
        function<int(int, int)> gcd = [&](int a, int b) {
            if (b == 0) return a;
            return gcd(b, a % b);
        };
        int q = 1;
        for (char s: s) {
            int len = 0;
            for (int i = s - 'A'; !vst[i]; i = c[i]) {
                vst[i] = true;
                len++;
            }
            if (len) q *= len / gcd(q, len);
        }
        cout << q - 1 << '\n';
    }
}