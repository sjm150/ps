#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    ll l, r;
    cin >> l >> r;
    int sz = r - l + 1;
    vector<int> d(sz, 0);
    for (ll i = 2; i * i <= r; i++) {
        for (ll j = (l + i - 1) / i * i; j <= r; j += i) {
            if (d[j - l] == 0) d[j - l] = i;
        }
    }
    int ans = 1;
    for (int i = 1; i < sz; i++) {
        if (d[i] == 0) {
            ans++;
            continue;
        }
        ll cur = i + l;
        while (cur % d[i] == 0) cur /= d[i];
        if (cur == 1) ans++;
    }
    cout << ans << '\n';
}