#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<int> w(n);
        for (int &w: w) cin >> w;
        vector<vector<bool>> poss(n, vector<bool>(n, false));
        for (int i = 0; i < n - 1; i++) {
            if (abs(w[i] - w[i + 1]) <= 1) poss[i][i + 1] = true;
        }
        for (int l = 4; l <= n; l += 2) {
            for (int i = 0; i + l - 1 < n; i++) {
                int j = i + l - 1;
                if (abs(w[i] - w[j]) <= 1 && poss[i + 1][j - 1]) {
                    poss[i][j] = true;
                    continue;
                }
                for (int k = i + 1; k < j; k += 2) {
                    if (poss[i][k] && poss[k + 1][j]) {
                        poss[i][j] = true;
                        continue;
                    }
                }
            }
        }
        vector<int> l(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            l[i] = l[i - 1];
            for (int j = i - 1; j >= 1; j -= 2) {
                if (poss[j - 1][i - 1]) l[i] = max(l[i], l[j - 1] + i - j + 1);
            }
        }
        cout << l[n] << '\n';
    }
}