#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        ll a, b; cin >> a >> b;
        ll g = gcd(a, b);
        ll ans = a / g * b;
        if (ans == b) {
            if (a == 1) ans = b * b;
            else {
                ll d = 2;
                for (; d * d <= b; d++) {
                    if (b % d == 0) break;
                }
                ans = d * b;
            }
        }
        cout << ans << '\n';
    }
}