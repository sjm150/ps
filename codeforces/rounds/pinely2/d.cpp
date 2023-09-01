#include <iostream>
using namespace std;
typedef pair<int, int> pi;

char grid[500][500];
pi opst[500][500];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        for (int i = 0; i < n; i++) {
            string line; cin >> line;
            for (int j = 0; j < m; j++) {
                grid[i][j] = line[j];
                opst[i][j] = {-1, -1};
            }
        }
        bool poss = true;
        for (int i = 0; i < n; i++) {
            int pu = -1, pd = -1;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'U') {
                    if (pu == -1) {
                        pu = j;
                    } else {
                        opst[i][pu] = {i, j};
                        pu = -1;
                    }
                } else if (grid[i][j] == 'D') {
                    if (pd == -1) {
                        pd = j;
                    } else {
                        opst[i][pd] = {i, j};
                        pd = -1;
                    }
                }
            }
            if (pu != -1 || pd != -1) poss = false;
        }
        if (poss) {
            for (int j = 0; j < m; j++) {
                int pl = -1, pr = -1;
                for (int i = 0; i < n; i++) {
                    if (grid[i][j] == 'L') {
                        if (pl == -1) {
                            pl = i;
                        } else {
                            opst[pl][j] = {i, j};
                            pl = -1;
                        }
                    } else if (grid[i][j] == 'R') {
                        if (pr == -1) {
                            pr = i;
                        } else {
                            opst[pr][j] = {i, j};
                            pr = -1;
                        }
                    }
                }
                if (pl != -1 || pr != -1) poss = false;
            }
        }

        if (poss) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 'L' || grid[i][j] == 'U') {
                        grid[i][j] = 'W';
                        auto [oi, oj] = opst[i][j];
                        if (oi != -1) {
                            grid[oi][oj] = 'B';
                        }
                    } else if (grid[i][j] == 'R' || grid[i][j] == 'D') {
                        grid[i][j] = 'B';
                        auto [oi, oj] = opst[i][j];
                        if (oi != -1) {
                            grid[oi][oj] = 'W';
                        }
                    }
                    cout << grid[i][j];
                }
                cout << '\n';
            }
        } else {
            cout << -1 << '\n';
        }
    }
}