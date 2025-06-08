#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        auto solve = [&]() {
            int d = a[1] - a[0];
            for (int i = 1; i < n; i++) {
                if (a[i] - a[i - 1] != d) return false;
            }
            int r = (d >= 0 ? a[0] : a[n - 1]) - abs(d);
            return r >= 0 && r % (n + 1) == 0;
        };

        cout << (solve() ? "YES\n" : "NO\n");
    }
}