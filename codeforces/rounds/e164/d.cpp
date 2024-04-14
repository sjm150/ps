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
    ll ovr = 0;
    ll ocnt = 0, ecnt = 0;
    ll ans = 0;
    for (int a: a) {
        ans = (ans + (ovr + (ocnt + ecnt) * (a & -2) % mod) / 2) % mod;
        if (a & 1) ans = (ans + ocnt + ecnt) % mod;
        else ans = (ans + ocnt) % mod;
        for (int i = 0; i <= mx; i++) {
            if (i <= a) ans = (ans + a * sum[i]) % mod;
            else ans = (ans + (i + a + 1) / 2 * sum[i]) % mod;
        }

        ovr = (ovr * 2 + (ocnt + ecnt) * (a & -2)) % mod;
        if (a & 1) ovr = (ovr + ocnt - ecnt + mod) % mod;
        ocnt = ecnt = (ocnt + ecnt) % mod;
        for (int i = mx; i > mx - a; i--) {
            int t = i + a;
            if (t & 1) {
                ovr = (ovr + (t & -2) * sum[i]) % mod;
                ocnt = (ocnt + sum[i]) % mod;
            } else {
                ovr = (ovr + t * sum[i]) % mod;
                ecnt = (ecnt + sum[i]) % mod;
            }
        }
        for (int i = mx - a; i >= 0; i--) sum[i + a] = (sum[i + a] + sum[i]) % mod;
    }

    cout << ans << '\n';
}