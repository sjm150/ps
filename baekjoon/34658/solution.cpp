#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const ll mod = 998244353;
    typedef struct Fwtree {
        vector<ll> val;
        Fwtree(int n): val(n + 1, 0) {}
        void add(int i, ll v) {
            i++;
            while (i < val.size()) {
                val[i] = (val[i] + v + mod) % mod;
                i += i & -i;
            }
        }
        ll get(int i) {
            i++;
            ll ret = 0;
            while (i > 0) {
                ret = (ret + val[i]) % mod;
                i &= i - 1;
            }
            return ret;
        }
    } fwt_t;

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &a: a) cin >> a;

    fwt_t ct(n + 1), xt(n + 1);
    auto comb = [&](ll x) { return x * (x - 1) / 2 % mod; };
    auto add = [&](int a, int c) {
        ct.add(a, c);
        xt.add(a, comb(a) * c);
    };
    auto cu = [&](int a) {
        ll cnt = ct.get(n) - ct.get(a);
        return (cnt * comb(a)) % mod;
    };
    auto calc = [&](int a) { return (cu(a) + xt.get(a)) % mod; };

    for (int a: a) add(a, 1);    
    ll ans = 0, same = 0;
    for (int a: a) {
        ans = (ans + cu(a)) % mod;
        same = (same + (ct.get(a) - ct.get(a - 1) - 1) * comb(a)) % mod;
    }
    ans = (ans + (mod + 1) / 2 * same) % mod;

    while (q--) {
        int v, x;
        cin >> v >> x;
        v--;
        add(a[v], -1);
        ans = (ans - calc(a[v]) + mod) % mod;
        a[v] += x;
        ans = (ans + calc(a[v])) % mod;
        add(a[v], 1);
        cout << ans << '\n';
    }
}