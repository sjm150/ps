#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

typedef struct DjSet {
    vector<int> p;
    int new_set() {
        p.push_back(-1);
        return p.size() - 1;
    }
    int find(int x) {
        if (p[x] == -1) return x;
        return p[x] = find(p[x]);
    }
    void uni(int a, int b) {
        a = find(a), b = find(b);
        if (a != b) p[a] = b;
    }
    bool insame(int a, int b) {
        a = find(a), b = find(b);
        return a == b;
    }
} djs_t;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int r, c;
char grid[1500][1500];
int vst[1500][1500];
pi l[2]; int lidx;
djs_t djs;
queue<pi> q[2];
int qcur = 0, qnxt = 1;

bool oob(int x, int y) {
    return x < 0 || r <= x || y < 0 || c <= y;
}

void dfs(int x, int y, int v) {
    vst[x][y] = v;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (oob(nx, ny) || vst[nx][ny]) continue;
        if (grid[nx][ny] == 'X') {
            vst[nx][ny] = v;
            q[qcur].emplace(nx, ny);
        } else {
            dfs(nx, ny, v);
        }
    }
}

void qswap() {
    qcur = 1 - qcur;
    qnxt = 1 - qnxt;
}

void melt() {
    while (!q[qcur].empty()) {
        auto [x, y] = q[qcur].front(); q[qcur].pop();
        int v = vst[x][y];
        grid[x][y] = '.';
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (oob(nx, ny)) continue;
            if (grid[nx][ny] == 'X') {
                if (vst[nx][ny] == 0) {
                    vst[nx][ny] = v;
                    q[qnxt].emplace(nx, ny);
                }
            } else {
                if (vst[nx][ny]) djs.uni(vst[nx][ny], v);
            }
        }
    }
    qswap();
}

int solve() {
    djs.new_set();
    dfs(l[0].first, l[0].second, djs.new_set());
    if (vst[l[1].first][l[1].second]) return 0;
    dfs(l[1].first, l[1].second, djs.new_set());
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (vst[i][j] || grid[i][j] == 'X') continue;
            dfs(i, j, djs.new_set());
        }
    }
    int t = 0;
    while (!djs.insame(1, 2)) {
        t++;
        melt();
    }
    return t;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'L') l[lidx++] = {i, j};
        }
    }
    cout << solve() << '\n';
}