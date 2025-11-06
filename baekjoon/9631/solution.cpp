#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int mod = 1e9 + 7;
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        long long ans = 1;
        int n = s.size(), len = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                len++;
            } else if (len) {
                int j = i - len - 1;
                if (j >= 0 && s[j] != s[i]) ans = ans * (len + 1) % mod;
                len = 0;
            }
        }
        cout << ans << '\n';
    }
}