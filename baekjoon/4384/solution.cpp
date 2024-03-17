#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> k(n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        tot += k[i];
    }

    vector<vector<bool>> sum(n / 2 + 2, vector<bool>(tot / 2 + 1, false));
    sum[0][0] = true;
    for (int k: k) {
        for (int i = n / 2 + 1; i; i--) {
            for (int j = k; j <= tot / 2; j++) {
                if (sum[i - 1][j - k]) sum[i][j] = true;
            }
        }
    }

    int maxs = 0;
    if (n & 1) {
        for (int i = tot / 2; i; i--) {
            if (sum[n / 2][i] || sum[n / 2 + 1][i]) {
                maxs = i;
                break;
            }
        }
    } else {
        for (int i = tot / 2; i; i--) {
            if (sum[n / 2][i]) {
                maxs = i;
                break;
            }
        }
    }

    cout << maxs << ' ' << tot - maxs << '\n';
}