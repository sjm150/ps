#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 200000;
const int mod = 1e9 + 7;

struct Fwtree {
    int cnt[mx + 1];
    ll val[mx + 1];

    void add(int i, int v) {
        i++;
        while (i <= mx) {
            cnt[i]++;
            val[i] += v;
            i += i & -i;
        }
    }

    int getc(int i) {
        i++;
        int ret = 0;
        while (i) {
            ret += cnt[i];
            i &= i - 1;
        }
        return ret;
    }

    ll getv(int i) {
        i++;
        ll ret = 0;
        while (i) {
            ret += val[i];
            i &= i - 1;
        }
        return ret;
    }
} fwt;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int x; cin >> x;
    fwt.add(x, x);

    ll ans = 1;
    for (int i = 1; i < n; i++) {
        cin >> x;
        int cnt = fwt.getc(x);
        ans *= (ll(2 * cnt - i) * x - 2 * fwt.getv(x) + fwt.getv(mx - 1)) % mod;
        ans = (ans % mod + mod) % mod;
        fwt.add(x, x);
    }
    cout << ans << '\n';
}