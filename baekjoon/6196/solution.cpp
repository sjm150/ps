#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int mod = 1e8;
    int n, m; cin >> n >> m;
    vector<int> blk(n + 1);
    for (int i = 1; i <= n; i++) {
        int b = 0;
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            b = b * 2 + 1 - x;
        }
        blk[i] = b;
    }

    int mx = 1 << m;
    vector<int> sta;
    for (int i = 0; i < mx; i++) {
        bool ok = true;
        for (int j = 3; ok && j < mx; j *= 2) {
            if ((i & j) == j) ok = false;
        }
        if (ok) sta.push_back(i);
    }
    int sz = sta.size();

    vector<vector<int>> cnt(n + 1, vector<int>(sz, 0));
    cnt[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < sz; j++) {
            if (sta[j] & blk[i]) continue;
            for (int k = 0; k < sz; k++) {
                if (!(sta[j] & sta[k])) {
                    cnt[i][j] += cnt[i - 1][k];
                    if (cnt[i][j] > mod) cnt[i][j] -= mod;
                }
            }
        }
    }

    cout << accumulate(cnt[n].begin(), cnt[n].end(), 0ll) % mod << '\n';
}