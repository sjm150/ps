#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    string s, t; cin >> s >> t;
    vector<vector<int>> cnt(n + 1, vector<int>(10, inf)), pre(n + 1, vector<int>(10, -1));
    cnt[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int d = t[i - 1] - s[i - 1];
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                int c = (j - k + 10) % 10 + (j - d + 10) % 10 + cnt[i - 1][k];
                if (cnt[i][j] > c) {
                    cnt[i][j] = c;
                    pre[i][j] = k;
                }
            }
        }
    }
    int mn = 0;
    for (int i = 0; i < 10; i++) {
        if (cnt[n][mn] > cnt[n][i]) mn = i;
    }
    cout << cnt[n][mn] << '\n';
    function<void(int, int)> prnt = [&](int i, int j) {
        if (i > 1) prnt(i - 1, pre[i][j]);
        cout << i << ' ' << (j - pre[i][j] + 10) % 10 * 2 - (cnt[i][j] - cnt[i - 1][pre[i][j]]) << '\n';
    };
    prnt(n, mn);
}