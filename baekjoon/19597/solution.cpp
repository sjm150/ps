#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> s(n, vector<string>(2));
        for (auto &s: s) {
            cin >> s[0];
            s[1] = s[0];
            reverse(s[1].begin(), s[1].end());
        }

        vector<vector<string>> rs(n, vector<string>(2));
        rs[0][0] = "0", rs[0][1] = "1";
        for (int i = 1; i < n; i++) {
            int mn = 0, mx = 1;
            if (rs[i - 1][0] > rs[i - 1][1]) swap(mn, mx);
            for (int j = 0; j < 2; j++) rs[i][j] = (s[i][j] > s[i - 1][mn] ? rs[i - 1][mn] : s[i][j] > s[i - 1][mx] ? rs[i - 1][mx] : "2") + char(j + '0');
        }

        cout << min(rs[n - 1][0], rs[n - 1][1]) << '\n';
    }
}