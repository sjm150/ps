#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> a(n, vector<int>(m));
        for (auto &a: a) {
            for (int &a: a) cin >> a;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j]) a[i][j] = (i + j) % k + 1;
            }
        }
        auto check = [&]() {
            vector<int> used(k);
            for (int i = 0; i < n; i++) {
                fill(used.begin(), used.end(), false);
                for (int j = 0; j < m; j++) {
                    if (a[i][j]) {
                        if (used[a[i][j] - 1]) return false;
                        else used[a[i][j] - 1] = true;
                    } else {
                        fill(used.begin(), used.end(), false);
                    }
                }
            }
            for (int j = 0; j < m; j++) {
                fill(used.begin(), used.end(), false);
                for (int i = 0; i < n; i++) {
                    if (a[i][j]) {
                        if (used[a[i][j] - 1]) return false;
                        else used[a[i][j] - 1] = true;
                    } else {
                        fill(used.begin(), used.end(), false);
                    }
                }
            }
            return true;
        };
        if (check()) {
            cout << "YES\n";
            for (auto &a: a) {
                for (int a: a) cout << a << ' ';
                cout << '\n';
            }
        } else {
            cout << "NO\n";
        }
    }
}