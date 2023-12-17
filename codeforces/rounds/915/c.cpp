#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        vector<pair<int, char>> sub;
        sub.emplace_back(n - 1, s[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            if (sub.back().second <= s[i]) sub.emplace_back(i, s[i]);
        }

        int m = sub.size();
        for (int i = 0; i < m; i++) s[sub[m - 1 - i].first] = sub[i].second;

        bool sorted = true;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] > s[i + 1]) sorted = false;
        }

        if (sorted) {
            int scnt = 0;
            for (; scnt < m; scnt++) {
                if (sub[m - 1].second != sub[m - 1 - scnt].second) break;
            }
            cout << m - scnt << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}