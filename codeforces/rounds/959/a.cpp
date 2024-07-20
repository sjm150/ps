#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (auto &a: a) {
            for (int &a: a) cin >> a;
        }
        if (n * m == 1) {
            cout << -1 << '\n';
        } else {
            for (auto &a: a) {
                for (int a: a) cout << a % (n * m) + 1 << ' ';
                cout << '\n';
            }
        }
    }
}