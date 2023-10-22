#include <bits/stdc++.h>
using namespace std;

int a[100000], b[100000];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        a[0] = m;
        for (int i = 1; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        sort(a, a + n);
        sort(b, b + n);
        for (int r = 0; r <= n; r++) {
            bool poss = true;
            for (int i = 0; i < n - r; i++) {
                if (a[i] >= b[i + r]) {
                    poss = false;
                    break;
                }
            }
            if (poss) {
                cout << r << '\n';
                break;
            }
        }
    }
}