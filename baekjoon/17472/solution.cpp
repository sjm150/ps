#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

typedef struct DjSet {
    vector<int> p;
    DjSet(int n) {
        p = vector<int>(n);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    bool uni(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        p[a] = b;
        return true;
    }
} djs_t;

int n, m;
int grid[10][10];

void bfs(int x, int y, int v) {
    queue<pi> q;
    grid[x][y] = v;
    q.emplace(x, y);
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
            if (grid[nx][ny] == 0 || grid[nx][ny] == v) continue;
            grid[nx][ny] = v;
            q.emplace(nx, ny);
        }
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int v = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) bfs(i, j, v++);
        }
    }

    vector<ti> edges;
    for (int i = 0; i < n; i++) {
        int pre = -1;
        for (int j = 0; j < m; j++) {
            if (!grid[i][j]) continue;
            if (pre >= 0 && grid[i][pre] != grid[i][j] && j - pre > 2) edges.emplace_back(j - pre - 1, grid[i][pre], grid[i][j]);
            pre = j;
        }
    }
    for (int j = 0; j < m; j++) {
        int pre = -1;
        for (int i = 0; i < n; i++) {
            if (!grid[i][j]) continue;
            if (pre >= 0 && grid[pre][j] != grid[i][j] && i - pre > 2) edges.emplace_back(i - pre - 1, grid[pre][j], grid[i][j]);
            pre = i;
        }
    }

    sort(edges.begin(), edges.end());
    djs_t djs(v);
    int minl = 0;
    for (auto [d, u, v]: edges) {
        if (djs.uni(u, v)) minl += d;
    }
    
    bool poss = true;
    for (int i = 3; i < v; i++) {
        if (djs.find(2) != djs.find(i)) {
            poss = false;
            break;
        }
    }
    if (poss) cout << minl << '\n';
    else cout << -1 << '\n';
}