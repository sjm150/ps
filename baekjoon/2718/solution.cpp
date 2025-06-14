#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int hb[] = {3, 6, 12, 15};
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> cnt(n + 1, vector<int>(16, 0));
        cnt[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 16; j++) {
                cnt[i][j] = cnt[i - 1][15 - j];
                for (int b: hb) {
                    if (b & j) continue;
                    cnt[i][j] += cnt[i - 1][15 - j - b];
                }
            }
        }
        cout << cnt[n][0] << '\n';
    }
}