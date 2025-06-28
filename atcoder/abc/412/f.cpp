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

    int n, c;
    cin >> n >> c;
    c--;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    a[c]++;

    int sum = accumulate(a.begin(), a.end(), -1);
    vector<pair<int, int>> ord(n);
    for (int i = 0; i < n; i++) ord[i] = {a[i], i};
    sort(ord.begin(), ord.end(), greater<pair<int, int>>());

    vector<ll> e(n);
    int pref = 0, epref = 0;
    for (auto [a, i]: ord) {
        e[i] = (sum + epref) * inv((pref + a - 1) % mod) % mod;
        pref = (pref + a) % mod;
        epref = (epref + a * e[i]) % mod;
    }
    cout << e[c] << '\n';
}