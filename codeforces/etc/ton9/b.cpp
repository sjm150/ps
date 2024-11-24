#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        bool ok = false;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                cout << s[i] << s[i + 1] << '\n';
                ok = true;
                break;
            }
        }
        if (!ok) {
            for (int i = 0; i < n - 2; i++) {
                if (s[i] != s[i + 2]) {
                    cout << s.substr(i, 3) << '\n';
                    ok = true;
                    break;
                }
            }
        }
        if (!ok) cout << -1 << '\n';
    }
}