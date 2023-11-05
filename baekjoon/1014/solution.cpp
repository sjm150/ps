#include <bits/stdc++.h>
using namespace std;

int get_xbit(vector<vector<char>> grid, int col) {
    int xbit = 0;
    for (int i = 0; i < grid.size(); i++) {
        xbit <<= 1;
        if (grid[i][col] == 'x') xbit |= 1;
    }
    return xbit;
}

int bitcnt(int bm) {
    int cnt = 0;
    for (int b = bm; b; b /= 2) {
        if (b % 2) cnt++;
    }
    return cnt;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int c; cin >> c;
    while (c--) {
        int n, m; cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        int mx = (1 << n) - 1;
        vector<vector<int>> cnt(m, vector<int>(mx + 1, 0));
        int xbit = get_xbit(grid, 0);
        for (int bm = 0; bm <= mx; bm++) {
            if (bm & xbit) continue;
            cnt[0][bm] = bitcnt(bm);
        }

        for (int j = 1; j < m; j++) {
            int xbit = get_xbit(grid, j);
            for (int nbm = 0; nbm <= mx; nbm++) {
                if (nbm & xbit) continue;
                int bcnt = bitcnt(nbm);
                for (int bm = 0; bm <= mx; bm++) {
                    if (nbm & (bm | (bm << 1) | (bm >> 1))) continue;
                    cnt[j][nbm] = max(cnt[j][nbm], cnt[j - 1][bm] + bcnt);
                }
            }
        }

        int maxc = 0;
        for (int bm = 0; bm <= mx; bm++) maxc = max(maxc, cnt[m - 1][bm]);
        cout << maxc << '\n';
    }
}