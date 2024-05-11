#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mx = 1e5 + 2;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vector<ll> sqrs(mx);
    for (ll i = 0; i < mx; i++) sqrs[i] = i * i;

    int t; cin >> t;
    while (t--) {
        int r; cin >> r;
        int cnt = 0;
        for (int i = 1; i <= r; i++) {
            cnt += lower_bound(sqrs.begin(), sqrs.end(), ll(r + 1) * (r + 1) - ll(i) * i) - lower_bound(sqrs.begin(), sqrs.end(), ll(r) * r - ll(i) * i);
        }
        cout << cnt * 4 << '\n';
    }
}