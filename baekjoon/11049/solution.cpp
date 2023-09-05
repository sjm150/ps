#include <bits/stdc++.h>
using namespace std;
const int inf = INT32_MAX;

int r[500], c[500];
int cnt[500][500];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> r[i] >> c[i];
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i + l <= n; i++) {
            int j = i + l - 1;
            cnt[i][j] = inf;
            for (int k = i; k < j; k++) {
                cnt[i][j] = min(cnt[i][j], cnt[i][k] + cnt[k + 1][j] + r[i] * c[k] * c[j]);
            }
        }
    }
    cout << cnt[0][n - 1] << '\n';
}