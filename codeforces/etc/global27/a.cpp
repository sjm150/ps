#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int n, m, r, c; cin >> n >> m >> r >> c;
        cout << ll(n - r) * (2 * m - 1) + m - c << '\n';
    }
}