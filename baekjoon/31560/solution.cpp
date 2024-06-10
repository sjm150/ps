#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> a(n);
    for (ll &a: a) cin >> a;

    ll bse = 0, sum = 0, ans = 0;
    for (ll a: a) {
        sum += bse;
        a += sum;
        ans += abs(a);
        bse -= a;
        sum -= a;
    }

    cout << ans << '\n';
}