#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int mx = 0;
        string ans;
        while (n--) {
            int c; cin >> c;
            string s; cin >> s;
            if (mx < c) {
                mx = c;
                ans = s;
            }
        }
        cout << ans << '\n';
    }
}