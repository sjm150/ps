#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        ll n, px, py, qx, qy;
        cin >> n >> px >> py >> qx >> qy;
        vector<ll> a(n);
        for (ll &a: a) cin >> a;
        auto sqr = [](ll x) { return x * x; };
        auto d = sqrt(sqr(px - qx) + sqr(py - qy));
        sort(a.begin(), a.end());
        ll sum = accumulate(a.begin(), prev(a.end()), 0ll), mx = a.back();
        cout << ((d - mx) * (d - mx) <= sum * sum ? "YES\n" : "NO\n");
    }
}