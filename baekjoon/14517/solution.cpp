#include <bits/stdc++.h>
using namespace std;
const int mod = 10007;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s; cin >> s;
    int n = s.size();
    vector<vector<int>> cnt(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) cnt[i][i] = 1;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == s[i]) cnt[i - 1][i] = 3;
        else cnt[i - 1][i] = 2;
    }

    for (int l = 3; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            if (s[i] == s[i + l - 1]) cnt[i][i + l - 1] = (cnt[i][i + l - 2] + cnt[i + 1][i + l - 1] + 1) % mod;
            else cnt[i][i + l - 1] = ((cnt[i][i + l - 2] + cnt[i + 1][i + l - 1] - cnt[i + 1][i + l - 2]) % mod + mod) % mod;
        }
    }

    cout << cnt[0][n - 1] << '\n';
}