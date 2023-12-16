#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll n, phi; cin >> n;
    phi = n;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i) continue;
        phi -= phi / i;
        while (n % i == 0) n /= i;
    }
    if (n != 1) phi -= phi / n;

    cout << phi << '\n';
}