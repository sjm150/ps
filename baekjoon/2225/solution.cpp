#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int mod = 1e9;
    int n, k;
    cin >> n >> k;
    vector<vector<long long>> cnt(k, vector<long long>(n + 1));
    fill(cnt[0].begin(), cnt[0].end(), 0);
    cnt[0][0] = 1;
    for (int i = 1; i < k; i++) {
        for (int j = 0; j <= n; j++) {
            for (int l = j; l <= n; l++) cnt[i][l] = (cnt[i][l] + cnt[i - 1][j]) % mod;
        }
    }
    cout << accumulate(cnt.back().begin(), cnt.back().end(), 0ll) % mod << '\n';
}