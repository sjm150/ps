#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    unordered_map<int, int> cnt;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        cnt[a]++;
        mx = max(mx, a);
    }
    
    vector<int> csum(mx + 1, 0);
    for (auto &[a, c]: cnt) csum[a] = c;
    for (int i = mx - 1; i >= 0; i--) csum[i] += csum[i + 1];

    ll ans = 0;
    for (auto &[a, c]: cnt) {
        for (int i = a; i <= mx; i += a) ans += ll(c) * csum[i];
        ans += ll(c - 1) * c / 2 - ll(c) * c;
    }
    cout << ans << '\n';
}