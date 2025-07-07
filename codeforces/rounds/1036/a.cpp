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
            for (int i = 0; i < n - 1; i++) {
                if (a[i] > a[i + 1]) return i;
            }
            return -1;
        };
        int idx = solve();
        if (idx < 0) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            cout << 2 << '\n';
            cout << a[idx] << ' ' << a[idx + 1] << '\n';
        }
    }
}