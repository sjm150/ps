#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const ll mx = 1e18;

map<ll, int> gval;

void init(ll l, ll r, int base) {
    int v = 0;
    ll pnt = 1;
    while (pnt <= l / base) {
        v++;
        pnt *= base;
    }

    gval.emplace(l, v);
    while (pnt <= r / base) gval.emplace(pnt *= base, v += 1);
    if (pnt > l) gval.emplace(pnt, v);
}

void init() {
    int v = 2;
    ll pnt = 4;
    while (pnt <= mx / 2) {
        init(pnt, 2 * pnt - 1, v);
        v++;
        pnt <<= 1;
    }
    init(pnt, mx, v);
    gval.emplace(mx + 1, 0);
}

int solve(ll l, ll r) {
    auto it = gval.upper_bound(l);
    if (it->first > r) return (r - l + 1) % mod * prev(it)->second % mod;

    ll sum = (it->first - l) % mod * prev(it)->second % mod;
    it++;
    while (it != gval.end() && it->first <= r) {
        sum = (sum + (it->first - prev(it)->first) % mod * prev(it)->second) % mod;
        it++;
    }
    it--;
    return (sum + (r - it->first + 1) % mod * it->second) % mod;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    init();
    int q; cin >> q;
    while (q--) {
        ll l, r; cin >> l >> r;
        cout << solve(l, r) << '\n';
    }
}