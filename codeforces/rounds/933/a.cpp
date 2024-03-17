#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> b(n), c(m);
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < m; i++) cin >> c[i];
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        int sum = 0;
        for (int b: b) sum += upper_bound(c.begin(), c.end(), k - b) - c.begin();
        cout << sum << '\n';
    }
}