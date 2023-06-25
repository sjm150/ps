#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

char grid[3][3];
bool vstd[3][3];

int dfs(int x, int y) {
    vstd[x][y] = true;
    int cnt = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < 3 && 0 <= ny && ny < 3 &&
            !vstd[nx][ny] && grid[nx][ny] == 'O') {
            cnt += dfs(nx, ny);
        }
    }
    return cnt;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;
    while (max_case--) {
        for (int i = 0; i < 3; i++) {
            string buf;
            cin >> buf;
            for (int j = 0; j < 3; j++) {
                grid[i][j] = buf[j];
                vstd[i][j] = false;
            }
        }

        vector<int> cnts;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!vstd[i][j] && grid[i][j] == 'O') {
                    cnts.emplace_back(dfs(i, j));
                }
            }
        }
        sort(cnts.begin(), cnts.end());

        bool matches = true;
        int n;
        cin >> n;
        if (n != cnts.size()) {
            matches = false;
        }
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (i >= cnts.size() || cnts[i] != a) matches = false;
        }

        cout << (matches ? 1 : 0) << '\n';
    }
}