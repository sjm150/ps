#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<vector<int>> idx(26);
        for (int i = 0; i < n; i++) idx[s[i] - 'a'].push_back(i);

        auto solve = [&]() {
            for (int i = 0; i < n - 1; i++) {
                if (s[i] <= s[i + 1]) continue;
                int mn = n;
                for (int j = s[i] - 'a' + 1; j < 26; j++) {
                    auto it = upper_bound(idx[j].begin(), idx[j].end(), i);
                    if (it != idx[j].end()) mn = min(mn, *it);
                }
                if (mn == i + 1) continue;
                return make_pair(i, mn - 1);
            }
            return make_pair(0, 0);
        };

        auto [l, r] = solve();
        rotate(s.begin() + l, s.begin() + l + 1, s.begin() + r + 1);
        cout << s << '\n';
    }
}