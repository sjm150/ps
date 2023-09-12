#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int d = 0;
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - 1 - i]) d++;
        }
        for (int l = 0; l <= n; l++) {
            if (l < d || n - d < l) {
                cout << 0;
            } else {
                if (s.length() % 2 == 1 || (l - d) % 2 == 0) cout << 1;
                else cout << 0;
            }
        }
        cout << '\n';
    }
}