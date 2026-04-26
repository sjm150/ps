#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll n, h, s; cin >> n >> h >> s;
    vector<ll> f(n);
    for (ll &f: f) cin >> f;
    double mx = min(double(h), double(s * 2) / n);
    double mn = double(s * 2) / n - mx;
    double l = 0, r = 0;
    for (int i = 0; i < n; i++) l += ((mx - mn) / n * (2 * i + 1) / 2 + mn) * f[i];
    for (int i = 0; i < n; i++) r += ((mx - mn) / n * (2 * i + 1) / 2 + mn) * f[n - 1 - i];
    cout << fixed << setprecision(6) << min(l, r) << '\n';
}