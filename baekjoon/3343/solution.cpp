#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void swap(int& a, int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll n;
    int a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    if (ll(a) * d < ll(c) * b) {
        swap(a, c);
        swap(b, d);
    }
    int g = gcd(a, c);
    ll minp = 1e18;
    for (int i = 0; i < a / g; i++) {
        ll p = ll(i) * d;
        ll r = n - ll(i) * c;
        if (r > 0) p += (r + a - 1) / a * b;
        minp = min(minp, p);
    }
    cout << minp << '\n';
}