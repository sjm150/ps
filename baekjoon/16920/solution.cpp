#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int n, m, p;
char grid[1000][1000];
int s[10], cnts[10];
queue<ti> q[10];

bool oob(int x, int y) {
    return x < 0 || n <= x || y < 0 || m <= y;
}

bool expand(int p) {
    if (q[p].empty()) return false;
    char pchar = p + '0';
    queue<ti> nq;
    while (!q[p].empty()) {
        auto [x, y, r] = q[p].front(); q[p].pop();
        if (r == 0) {
            nq.emplace(x, y, s[p]);
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (oob(nx, ny) || grid[nx][ny] != '.') continue;
            grid[nx][ny] = pchar;
            cnts[p]++;
            q[p].emplace(nx, ny, r - 1);
        }
    }
    while (!nq.empty()) {
        q[p].push(nq.front());
        nq.pop();
    }
    return true;
}

bool expand() {
    bool expanded = false;
    for (int i = 1; i <= p; i++) {
        if (expand(i)) expanded = true;
    }
    return expanded;
}

void print() {
    cout << "---------------------\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << grid[i][j];
        cout << endl;
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m >> p;
    for (int i = 1; i <= p; i++) cin >> s[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] != '#' && grid[i][j] != '.') {
                int p = grid[i][j] - '0';
                q[p].emplace(i, j, s[p]);
                cnts[p]++;
            }
        }
    }
    while (expand()) {}
    for (int i = 1; i <= p; i++) cout << cnts[i] << ' ';
    cout << '\n';
}