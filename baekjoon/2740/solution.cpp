#include <bits/stdc++.h>
using namespace std;

int a[100][100], b[100][100], c[100][100];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    cin >> m >> k;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int l = 0; l < m; l++) {
            for (int j = 0; j < k; j++) {
                c[i][j] += a[i][l] * b[l][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) cout << c[i][j] << ' ';
        cout << '\n';
    }
}