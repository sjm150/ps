#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        int res = 1, i = 0;
        for (; i < n - 1 - i; i++) {
            if (s[i] != s[n - 1 - i]) {
                res = 0;
                break;
            }
        }
        cout << res << ' ' << i + 1 << '\n';
    }
}