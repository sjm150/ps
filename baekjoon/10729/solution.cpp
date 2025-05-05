#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const int mod = 1e9 + 7;
    auto inv = [&](ll x) {
        ll ret = 1;
        for (int i = mod - 2; i; i /= 2) {
            if (i % 2) ret = ret * x % mod;
            x = x * x % mod;
        }
        return ret;
    };
    int n, k, m; cin >> n >> k >> m;
    ll ik = inv(k + 1);
    vector<int> p(max(n, m + 1), 0);
    p[m] = 1;
    ll sum = 0;
    for (int i = m - 1; i >= 0; i--) {
        sum += (n <= i - k + n && i - k + n <= m ? p[i - k + n] : 0) - (i + n + 1 <= m ? p[i + n + 1] : 0);
        p[i] = (sum % mod + mod) * ik % mod;
    }
    for (int i = 0; i < n; i++) cout << p[i] << '\n';
}