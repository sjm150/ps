#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

bool poss(int n, int m) {
    int g = gcd(n, m);
    ll unitrev = m / g;
    ll i = 1;
    while (i < unitrev) i *= 2;
    return i == unitrev;
}

ll solve(int n, int m) {
    ll cnt = 0;
    if (!poss(n, m)) return -1;
    while (n) {
        n = n % m;
        cnt += n;
        n *= 2;
    }
    return cnt;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        cout << solve(n, m) << '\n';
    }
}