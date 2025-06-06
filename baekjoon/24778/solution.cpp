#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int mx = 1 << 18;
    vector<vector<int>> d(3, vector<int>(3));
    for (auto &d: d) {
        for (int &d: d) cin >> d;
    }

    int ans = mx;
    for (int b = 0; b < mx; b++) {
        auto v = d;
        int cur = 0;
        for (int i = 0, x = b; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    v[i][k] += x % 4;
                    if (k != i) v[k][j] += x % 4;
                }
                cur += x % 4;
                x /= 4;
            }
        }

        bool ok = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (v[i][j] % 4) ok = false;
            }
        }
        if (ok && ans > cur) ans = cur;
    }

    cout << (ans < mx ? ans : -1) << '\n';
}