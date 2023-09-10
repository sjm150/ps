#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int h, w;
char grid[100][100];
bool vst[100][100];
bool key[26];
queue<pi> blocked[26];
int cnt;

bool is_upper(char c) {
    return 'A' <= c && c <= 'Z';
}

bool is_lower(char c) {
    return 'a' <= c && c <= 'z';
}

bool oob(int x, int y) {
    return x < 0 || h <= x || y < 0 || w <= y;
}

void bfs(queue<pi> q) {
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        char c = grid[x][y];
        if (c == '$') {
            cnt++;
        } else if (is_lower(c) && !key[c - 'a']) {
            key[c - 'a'] = true;
            while (!blocked[c - 'a'].empty()) {
                auto [bx, by] = blocked[c - 'a'].front(); blocked[c - 'a'].pop();
                q.emplace(bx, by);
            }
        } else if (is_upper(c) && !key[c - 'A']) {
            blocked[c - 'A'].emplace(x, y);
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (oob(nx, ny) || vst[nx][ny] || grid[nx][ny] == '*') continue;
            vst[nx][ny] = true;
            q.emplace(nx, ny);
        }
    }
}

void init() {
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
            vst[i][j] = false;
        }
    }
    fill(key, key + 26, false);
    for (int i = 0; i < 26; i++) {
        while (!blocked[i].empty()) blocked[i].pop();
    }
    string ks; cin >> ks;
    if (ks[0] != '0') {
        for (char k: ks) key[k - 'a'] = true;
    }
    cnt = 0;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        init();
        queue<pi> q;
        vector<pi> boarder;
        for (int i = 0; i < h; i++) {
            boarder.emplace_back(i, 0);
            boarder.emplace_back(i, w - 1);
        }
        for (int j = 1; j < w - 1; j++) {
            boarder.emplace_back(0, j);
            boarder.emplace_back(h - 1, j);
        }
        for (auto [x, y]: boarder) {
            if (grid[x][y] == '*') continue;
            vst[x][y] = true;
            q.emplace(x, y);
        }
        bfs(q);
        cout << cnt << '\n';
    }
}