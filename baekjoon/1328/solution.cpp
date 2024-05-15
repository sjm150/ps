#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, l, r; cin >> n >> l >> r;
    if (l == 1 && r == 1) {
        cout << (n == 1 ? 1 : 0) << '\n';
        return 0;
    }

    vector<vector<int>> cnt(max(l + 1, 3), vector<int>(max(r + 1, 3), 0));
    cnt[2][1] = cnt[1][2] = 1;
    for (int k = 2; k < n; k++) {
        for (int i = l; i >= 1; i--) {
            for (int j = r; j >= 1; j--) {
                cnt[i][j] = ((long long)(k - 1) * cnt[i][j] + cnt[i - 1][j] + cnt[i][j - 1]) % mod;
            }
        }
    }
    cout << cnt[l][r] << '\n';
}