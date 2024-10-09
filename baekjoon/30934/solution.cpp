#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 998244353;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    auto inv = [](ll x) {
        ll r = 1;
        for (int e = mod - 2; e; e /= 2) {
            if (e % 2) r = r * x % mod;
            x = x * x % mod;
        }
        return r;
    };
    int invs[7];
    for (int i = 1; i <= 6; i++) invs[i] = inv(i);
    int n; cin >> n;
    map<int, vector<ll>> p;
    for (int i = 1; i <= 6; i++) p.emplace(i, vector<ll>(i, invs[i]));
    function<void(int)> calc = [&](int l) {
        auto it = p.find(l);
        if (it != p.end()) return;
        calc(l - l / 6);
        if (l % 6) calc(l - l / 6 - 1);
        vector<ll> pl(l, 0);
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < 6; j++) {
                if (j != i % 6) pl[i] = (pl[i] + p[l - l / 6 - (j < l % 6)][i - i / 6 - (j < i % 6)] * invs[6]) % mod;
            }
        }
        p[l] = pl;
    };
    calc(n);
    for (int i = 0; i < n; i++) cout << p[n][i] << '\n';
}