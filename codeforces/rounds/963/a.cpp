#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;  cin >> n;
        string s; cin >> s;
        int r[4] = {n, n, n, n};
        int ans = 0;
        for (char c: s) {
            if (c == '?') continue;
            if (r[c - 'A']) {
                ans++;
                r[c - 'A']--;
            }
        }
        cout << ans << '\n';
    }
}