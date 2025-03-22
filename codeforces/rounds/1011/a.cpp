#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        if (k == 0) {
            bool ok = false;
            for (int i = 0; i < n; i++) {
                if (s[i] < s[n - 1 - i]) {
                    ok = true;
                    break;
                } else if (s[i] > s[n - 1 - i]) {
                    break;
                }
            }
            cout << (ok ? "YES\n" : "NO\n");
        } else {
            bool same = true;
            for (char c: s) {
                if (c != s[0]) {
                    same = false;
                    break;
                }
            }
            cout << (same ? "NO\n" : "YES\n");
        }
    }
}