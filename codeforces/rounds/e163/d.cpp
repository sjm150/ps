#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        int ans = 0;
        vector<vector<int>> cnt(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (s[i - 1] == s[j - 1] || s[i - 1] == '?' || s[j - 1] == '?') {
                    cnt[i][j] = cnt[i - 1][j - 1] + 1;
                    if (j - i == cnt[i][j]) ans = max(ans, cnt[i][j]);
                }
            }
        }
        cout << ans * 2 << '\n';
    }
}