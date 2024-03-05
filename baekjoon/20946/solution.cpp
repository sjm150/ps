#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll n; cin >> n;
    vector<ll> p;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            p.push_back(i);
            n /= i;
        }
    }

    if (p.empty()) {
        cout << -1 << '\n';
        return 0;
    }
    if (n > 1) p.push_back(n);

    int m = p.size();
    for (int i = 0; i < m - 3; i += 2) cout << p[i] * p[i + 1] << ' ';
    if (m & 1) cout << p[m - 3] * p[m - 2] * p[m - 1] << '\n';
    else cout << p[m - 2] * p[m - 1] << '\n';;
}