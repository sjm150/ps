#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vector<ll> b = {1};
    while (b.back() < 1e17) b.push_back(b.back() * 10 + 1);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        ll k; cin >> k;
        vector<ll> ans;
        while (k) {
            ll d = *prev(upper_bound(b.begin(), b.end(), k));
            ll t = k / d;
            if (t > 9) t = 9;
            t *= d;
            ans.push_back(t);
            k -= t;
        }
        cout << ans.size() << '\n';
        for (ll a: ans) cout << a << ' ';
        cout << '\n';
    }
}