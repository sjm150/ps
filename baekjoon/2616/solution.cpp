#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int k; cin >> k;

    int sum = 0;
    for (int i = 0; i < k; i++) sum += a[i];
    vector<vector<int>> cnt(3, vector<int>(n, 0));
    cnt[0][k - 1] = sum;
    for (int i = k; i < n; i++) {
        sum += a[i] - a[i - k];
        cnt[0][i] = sum;
    }

    for (int i = 1; i <= 2; i++) {
        int maxc = cnt[i - 1][i * k - 1];
        for (int j = (i + 1) * k - 1; j < n; j++) {
            cnt[i][j] = maxc + cnt[0][j];
            maxc = max(maxc, cnt[i - 1][j - k + 1]);
        }
    }

    int ans = 0;
    for (int c: cnt[2]) ans = max(ans, c);
    cout << ans << '\n';
}