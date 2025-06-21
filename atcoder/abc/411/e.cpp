#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const int mod = 998244353;
    auto inv = [&](ll x) {
        ll ret = 1;
        for (int i = mod - 2; i; i /= 2) {
            if (i % 2) ret = ret * x % mod;
            x = x * x % mod;
        }
        return ret;
    };
    vector<ll> iv(7);
    for (int i = 1; i <= 6; i++) iv[i] = inv(i);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(6));
    for (auto &a: a) {
        for (int &a: a) cin >> a;
        sort(a.begin(), a.end());
    }

    int lb = 0;
    for (auto &a: a) lb = max(lb, a[0]);
    set<int> s;
    for (auto &a: a) {
        for (int a: a) {
            if (a >= lb) s.insert(a);
        }
    }

    vector<pair<int, ll>> pref;
    for (auto &a: a) {
        for (int i = 0; i < 6; i++) pref.emplace_back(a[i], i);
    }
    sort(pref.begin(), pref.end());
    ll prd = 1;
    for (auto &[a, p]: pref) {
        prd = prd * (p == 0 ? iv[6] : (p + 1) * iv[p] % mod) % mod;
        p = prd;
    }
    auto prob = [&](int ub) {
        if (ub < lb) return 0ll;
        auto it = upper_bound(pref.begin(), pref.end(), make_pair(ub, ll(mod)));
        return prev(it)->second;
    };

    ll ans = 0;
    for (int a: s) {
        ll p = (prob(a) - prob(a - 1) + mod) % mod;
        ans = (ans + p * a) % mod;
    }
    cout << ans << '\n';
}