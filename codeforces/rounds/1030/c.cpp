#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const ll inf = 1e18;
    int t; cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        int ans = 0;
        vector<ll> cst;
        for (int a: a) {
            for (ll b = 1; b < inf; b *= 2) {
                if (b & a) ans++;
                else cst.push_back(b);
            }
        }
        sort(cst.begin(), cst.end());

        for (ll c: cst) {
            if (k < c) {
                break;
            } else {
                k -= c;
                ans++;
            }
        }
        cout << ans << '\n';
    }
}