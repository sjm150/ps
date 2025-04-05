#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        int r = min(n - m * k, n / (m + 1));
        if (r < k) {
            for (int i = 0; i < n; i++) cout << (i % k < r ? i % k % r : 0) << ' ';
        } else {
            for (int i = 0; i < n; i++) cout << i % r << ' ';
        }
        cout << '\n';
    }
}