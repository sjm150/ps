#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int n, m;
int blk[1000][1000];
int vst[1000][1000];
vector<int> cnts;

bool oob(int x, int y) {
    return x < 0 || n <= x || y < 0 || m <= y;
}

int dfs(int x, int y, int v) {
    vst[x][y] = v;
    int cnt = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (oob(nx, ny) || blk[nx][ny] || vst[nx][ny]) continue;
        cnt += dfs(nx, ny, v);
    }
    return cnt;
}

void calc_cnt(int x, int y) {
    set<int> s;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (oob(nx, ny) || blk[nx][ny]) continue;
        s.insert(vst[nx][ny]);
    }
    for (int i: s) {
        blk[x][y] += cnts[i];
        if (blk[x][y] >= 10) blk[x][y] -= 10;
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string line; cin >> line;
        for (int j = 0; j < m; j++) {
            if (line[j] == '1') blk[i][j] = 1;
            else blk[i][j] = 0;
        }
    }
    cnts.push_back(0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!blk[i][j] && vst[i][j] == 0) cnts.push_back(dfs(i, j, cnts.size()) % 10);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blk[i][j]) calc_cnt(i, j);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << blk[i][j];
        cout << '\n';
    }
}