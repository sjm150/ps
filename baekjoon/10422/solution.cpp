#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vector<vector<int>> cnt(5001, vector<int>(2502));
    fill(cnt[0].begin(), cnt[0].end(), 0);
    cnt[0][0] = 1;
    for (int i = 1; i <= 5000; i++) {
        cnt[i][0] = cnt[i - 1][1];
        for (int j = 1; j <= 2500; j++) cnt[i][j] = (cnt[i - 1][j - 1] + cnt[i - 1][j + 1]) % mod;
    }

    int t; cin >> t;
    while (t--) {
        int l; cin >> l;
        cout << cnt[l][0] << '\n';
    }
}