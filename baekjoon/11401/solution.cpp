#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

vector<int> prms;

void initp(int n) {
    vector<bool> isp(n + 1, true);
    for (ll i = 2; i <= n; i++) {
        if (!isp[i]) continue;
        prms.push_back(i);
        for (ll j = i * i; j <= n; j += i) isp[j] = false;
    }
}

int count(int x, int s, int e) {
    return (e - (s - 1) / x * x) / x;
}

int countp(int p, int s, int e) {
    int cnt = 0;
    for (ll i = p; i <= e; i *= p) cnt += count(i, s, e);
    return cnt;
}

ll pow(int n, int x) {
    if (x == 0) return 1;
    ll t = pow(n, x / 2);
    ll ret = (t * t) % mod;
    if (x % 2) ret = (ret * n) % mod;
    return ret;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    if (k > n - k) k = n - k;
    initp(n);
    ll ans = 1;
    for (int p: prms) ans = (ans * pow(p, countp(p, n - k + 1, n) - countp(p, 1, k))) % mod;
    cout << ans << '\n';
}