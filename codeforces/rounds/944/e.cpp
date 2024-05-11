#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k, q; cin >> n >> k >> q;
        vector<int> a(k + 1), b(k + 1);
        a[0] = b[0] = 0;
        for (int i = 1; i <= k; i++) cin >> a[i];
        for (int i = 1; i <= k; i++) cin >> b[i];

        while (q--) {
            int d; cin >> d;
            if (d == n) {
                cout << b.back() << ' ';
                continue;
            }
            int idx = upper_bound(a.begin(), a.end(), d) - a.begin() - 1;
            cout << b[idx] + (long long)(b[idx + 1] - b[idx]) * (d - a[idx]) / (a[idx + 1] - a[idx]) << ' ';
        }
        cout << '\n';
    }
}