#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const int mod = 1e6;
    ll n; cin >> n;
    unordered_map<ll, ll> mem;
    mem[0] = 0, mem[1] = 1, mem[2] = 1;
    function<ll(ll)> f = [&](ll n) {
        if (mem.find(n) != mem.end()) return mem[n];
        ll k = (n + 1) / 2;
        return mem[n] = (f(k) * f(n - k + 1) + f(k - 1) * f(n - k)) % mod;
    };
    cout << f(n) << '\n';
}