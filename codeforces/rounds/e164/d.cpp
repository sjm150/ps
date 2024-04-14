#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mx = 5000;
const int mod = 998244353;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    sort(a.begin(), a.end());

    vector<ll> sum(mx + 1, 0);
    sum[0] = 1;
    ll ans = 0;
    for (int a: a) {
        for (int i = 0; i <= mx; i++) {
            if (i <= a) ans = (ans + a * sum[i]) % mod;
            else ans = (ans + (i + a + 1) / 2 * sum[i]) % mod;
        }
        for (int i = mx - a; i >= 0; i--) sum[i + a] = (sum[i + a] + sum[i]) % mod;
    }

    cout << ans << '\n';
}