#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int mod = 9901;
    int n;
    cin >> n;
    vector<vector<int>> cnt(n, vector<int>(3));
    cnt[0][0] = cnt[0][1] = cnt[0][2] = 1;
    for (int i = 1; i < n; i++) {
        cnt[i][0] = (cnt[i - 1][0] + cnt[i - 1][1] + cnt[i - 1][2]) % mod;
        cnt[i][1] = (cnt[i - 1][0] + cnt[i - 1][2]) % mod;
        cnt[i][2] = (cnt[i - 1][0] + cnt[i - 1][1]) % mod;
    }
    cout << (cnt[n - 1][0] + cnt[n - 1][1] + cnt[n - 1][2]) % mod << '\n';
}