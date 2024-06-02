#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];

        bool poss = true;
        int prod = 1;
        for (int b: b) {
            if (b == 1 || b == 7 || b == 17 || b == 119 || b == 289 || b == 2023) {
                prod *= b;
                if (prod > 2023) {
                    poss = false;
                    break;
                }
            } else {
                poss = false;
                break;
            }
        }

        if (poss && (2023 % prod == 0)) {
            cout << "YES\n";
            cout << 2023 / prod << ' ';
            for (int i = 1; i < k; i++) cout << 1 << ' ';
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
}