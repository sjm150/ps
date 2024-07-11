#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;

    vector<vector<int>> cnt(4, vector<int>(k + 1, 0));
    auto loop = [&]() {
        vector<int> cur(k + 1);
        cur[0] = 0;
        for (int j = 1; j <= k; j++) cur[j] = ((cnt[0][j - 1] + cnt[2][j - 1]) % mod + cnt[3][j - 1]) % mod;
        cur[k] = ((cur[k] + cnt[0][k]) % mod + (cnt[2][k] + cnt[3][k]) % mod) % mod;

        for (int j = 0; j <= k; j++) cnt[3][j] = (cnt[2][j] + cnt[3][j]) % mod;
        swap(cnt[1], cnt[2]);
        swap(cnt[0], cnt[1]);
        swap(cnt[0], cur);
    };

    cnt[0][0] = 1;
    for (int i = 0; i < n; i++) loop();
    int ans = ((cnt[0][k] + cnt[2][k - 1]) % mod + cnt[2][k]) % mod;

    for (auto &cnt: cnt) fill(cnt.begin(), cnt.end(), 0);
    cnt[0][1] = 1;
    for (int i = 2; i < n; i++) loop();
    cout << ((ans + cnt[0][k]) % mod + (cnt[2][k] + cnt[2][k - 1]) % mod) % mod << '\n';
}