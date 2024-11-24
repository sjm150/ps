#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const int mx = 1e5;
    vector<int> idx(mx + 1, 0);
    for (int i = 2; i <= mx; i++) {
        for (ll j = 1; j * j <= i; j++) {
            if (i % j) continue;
            idx[i] = max(idx[i], max(idx[j], idx[i / j]) + 1);
        }
    }
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> s(m);
        for (int &s: s) cin >> s;
        reverse(s.begin(), s.end());
        if (*max_element(idx.begin(), idx.begin() + n + 1) >= m) {
            cout << -1 << '\n';
        } else {
            for (int i = 1; i <= n; i++) cout << s[idx[i]] << ' ';
            cout << '\n';
        }
    }
}