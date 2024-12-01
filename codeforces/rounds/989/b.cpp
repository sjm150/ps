#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        string s; cin >> s;
        int cnt = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                cnt++;
                if (cnt == m) {
                    for (int j = 0; j < k && i + j < n; j++) s[i + j] = '1';
                    cnt = 0;
                    ans++;
                }
            } else {
                cnt = 0;
            }
        }
        cout << ans << '\n';
    }
}