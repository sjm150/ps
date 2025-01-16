#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef pair<string, int> psi;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        map<string, int> cnt;
        while (n--) {
            string s; cin >> s;
            int c; cin >> c;
            cnt[s] += c;
        }
        vector<psi> ans;
        for (auto &c: cnt) ans.emplace_back(c);
        sort(ans.begin(), ans.end(), [](psi &a, psi &b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        });
        cout << ans.size() << '\n';
        for (auto &[s, c]: ans) cout << s << ' ' << c << '\n';
    }
}