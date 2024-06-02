#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        if (n == k) {
            cout << "YES\n";
            cout << 1 << '\n' << 1 << '\n';
            continue;
        }
        if (k == 1) {
            cout << "YES\n";
            cout << 1 << '\n' << n << '\n';
            continue;
        }

        if (2 * k - 1 <= n) {
            cout << "YES\n";
            cout << 2 << '\n';
            cout << n - k + 1 << ' ' << 1 << '\n';
        } else {
            cout << "NO\n";
        }
    }
}