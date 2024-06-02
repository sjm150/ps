#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        int q = n / m;
        if (n % m) q++;
        m = min(n, m);
        cout << ((m > 1 && q < n - k) || m > k + 1 ? "YES\n" : "NO\n");
    }
}