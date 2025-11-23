#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m));
    for (auto &g: grid) {
        for (int &g: g) cin >> g;
    }

    long long ans = 0;
    for (int s = 0; s < n; s++) {
        vector<int> sum(m, 0);
        for (int e = s; e < n; e++) {
            for (int i = 0; i < m; i++) sum[i] += grid[e][i];
            vector<int> ps = {0};
            int psum = 0;
            for (int i = 0; i < m; i++) {
                psum = (psum + sum[i]) % k;
                ps.push_back(psum);
            }
            sort(ps.begin(), ps.end());
            int cnt = 0;
            for (int i = 0; i <= m; i++) {
                cnt++;
                if (i == m || ps[i] != ps[i + 1]) {
                    ans += cnt * (cnt - 1) / 2;
                    cnt = 0;
                }
            }
        }
    }

    cout << ans << '\n';
}