#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

pl eea(ll a, ll b) {
    if (a == 1 && b == 0) return pl(1, 0);
    auto [x, y] = eea(b, a % b);
    return pl(y, x - a / b * y);
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll n, a; cin >> n >> a;
    cout << (n - a) % n << ' ' << (gcd(n, a) == 1 ? (eea(a, n).first + n) % n : -1) << '\n';
}