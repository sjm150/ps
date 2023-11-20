#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        int d = k - m - n + 2;

        if (d < 0 || d % 2 != 0) {
            cout << "NO\n";
            continue;
        } else {
            cout << "YES\n";
        }


        if (n < m) {
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < m - 1; j++) cout << "R ";
                cout << '\n';
            }
            for (int j = 0; j < m - 1; j++) {
                if (j % 2) cout << "B ";
                else cout << "R ";
            }
            cout << '\n';
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < m; j++) cout << "B ";
                cout << '\n';
            }
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m - 1; j++) cout << "R ";
                cout << '\n';
            }
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < m - 1; j++) cout << "B ";
                if (i % 2) cout << "R\n";
                else cout << "B\n";
            }
        }
    }
}