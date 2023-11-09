#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> initsb() {
    vector<vector<int>> sb(19, vector<int>(19, 1));
    for (int n = 2; n <= 10; n++) {
        fill(sb[n - 1].begin() + n - 1, sb[n - 1].end() - n + 1, n);
        fill(sb[19 - n].begin() + n - 1, sb[19 - n].end() - n + 1, n);
        for (int i = n; i < 19 - n; i++) sb[i][n - 1] = sb[i][19 - n] = n;
    }
    return sb;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    auto sb = initsb();
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n + 1, vector<char>(m + 1));
    vector<vector<int>> scnt(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            scnt[i][j] = scnt[i - 1][j] + scnt[i][j - 1] - scnt[i - 1][j - 1] + (grid[i][j] == '1' ? 1 : 0);
        }
    }

    bool poss = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int si = max(1, i - 9), sj = max(1, j - 9);
            int ei = min(n, i + 9), ej = min(m, j + 9);
            if (scnt[ei][ej] - scnt[si - 1][ej] - scnt[ei][sj - 1] + scnt[si - 1][sj - 1] != 10) continue;
            int sum = 0;
            for (int ii = 0; ii < 19; ii++) {
                int ci = i + ii - 9;
                if (ci <= 0 || n < ci) continue;
                for (int jj = 0; jj < 19; jj++) {
                    int cj = j + jj - 9;
                    if (cj <= 0 || m < cj) continue;
                    if (grid[ci][cj] == '1') sum += 1 << sb[ii][jj] - 1;
                }
            }
            if (poss = (sum == 1023)) {
                cout << i - 1 << ' ' << j - 1 << '\n';
                break;
            }
        }
        if (poss) break;
    }
    if (!poss) cout << -1 << '\n';
}