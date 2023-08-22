#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int r, c;
int apm[2], aidx;
int fd[2][50][50];
int cur = 0, nxt = 1;

void swap() {
    if (cur == 0) cur = 1, nxt = 0;
    else cur = 0, nxt = 1;
}

bool oob(int x, int y) {
    return x < 0 || r <= x || y < 0 || c <= y || fd[cur][x][y] == -1;
}

vector<pi> adj(int x, int y) {
    vector<pi> adjs;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!oob(nx, ny)) adjs.emplace_back(nx, ny);
    }
    return adjs;
}

void diffu() {
    for (int i = 0; i < r; i++) fill(fd[nxt][i], fd[nxt][i] + c, 0);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (fd[cur][i][j] == -1) continue;
            auto adjs = adj(i, j);
            int unit = fd[cur][i][j] / 5;
            fd[nxt][i][j] += fd[cur][i][j] - unit * adjs.size();
            for (auto [nx, ny]: adjs) fd[nxt][nx][ny] += unit;
        }
    }
    swap();
}

void circu() {
    int i = 0;
    int x = apm[0], y = 0;
    while (i < 4) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        fd[cur][x][y] = fd[cur][nx][ny];
        x = nx, y = ny;
        if (i == 0 && x == 0) i++;
        else if (i == 1 && y == c - 1) i++;
        else if (i == 2 && x == apm[0]) i++;
        else if (i == 3 && y == 1) i++;
    }
    fd[cur][apm[0]][0] = -1;
    fd[cur][apm[0]][1] = 0;
    i = 0;
    x = apm[1], y = 0;
    while (i < 4) {
        int nx = x - dx[i];
        int ny = y + dy[i];
        fd[cur][x][y] = fd[cur][nx][ny];
        x = nx, y = ny;
        if (i == 0 && x == r - 1) i++;
        else if (i == 1 && y == c - 1) i++;
        else if (i == 2 && x == apm[1]) i++;
        else if (i == 3 && y == 1) i++;
    }
    fd[cur][apm[1]][0] = -1;
    fd[cur][apm[1]][1] = 0;
}

void simul() {
    diffu();
    circu();
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> r >> c >> t;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> fd[cur][i][j];
            if (fd[cur][i][j] == -1) apm[aidx++] = i;
        }
    }
    while (t--) simul();
    int sum = 0;
    fd[cur][apm[0]][0] = fd[cur][apm[1]][0] = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sum += fd[cur][i][j];
        }
    }
    cout << sum << '\n';
}