#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> b(n);
        for (int &b: b) cin >> b;
        vector<tuple<int, int, int>> xyz(q);
        for (auto &[x, y, z]: xyz) {
            cin >> x >> y >> z;
            x--, y--, z--;
        }
        reverse(xyz.begin(), xyz.end());

        const int inf = 1e9;
        vector<int> mn(n), mx(n);
        for (int i = 0; i < n; i++) mn[i] = mx[i] = b[i];
        auto solve = [&]() {
            for (auto [x, y, z]: xyz) {
                if (x == z || y == z) {
                    if (x == y) continue;
                    if (y == z) swap(x, y);
                    if (mx[y] < mn[z]) return false;
                    if (mn[y] <= mx[z]) mx[z] = inf;
                    mn[y] = max(mn[y], mn[z]);
                } else {
                    if (mn[z] > min(mx[x], mx[y]) || mx[z] < min(mn[x], mn[y])) return false;
                    mn[x] = max(mn[x], mn[z]);
                    mn[y] = max(mn[y], mn[z]);
                    if (x == y) mx[x] = min(mx[x], mx[z]);
                    mn[z] = 0, mx[z] = inf;
                }
            }
            for (int i = 0; i < n; i++) {
                if (mx[i] < mn[i]) return false;
            }
            return true;
        };

        if (solve()) {
            for (int a: mn) cout << a << ' ';
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}