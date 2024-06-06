#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        string s; cin >> s;
        vector<int> cnt(7, 0);
        for (char c: s) cnt[c - 'A']++;
        int ans = 0;
        for (int c: cnt) ans += max(0, m - c);
        cout << ans << '\n';
    }
}