#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

char team[5][5];
bool sel[5][5];
int num_s;
int cnt;

bool is_connected() {
    queue<pair<int, int>> q;
    bool vst[5][5] = {};
    int conn = 0;

    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            if (sel[x][y]) {
                q.emplace(x, y);
                vst[x][y] = true;
                break;
            }
        }
        if (!q.empty()) break;
    }

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        conn++;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < 5 && 0 <= ny && ny < 5
                && !vst[nx][ny] && sel[nx][ny]) {
                q.emplace(nx, ny);
                vst[nx][ny] = true;
            }
        }
    }

    return conn == 7;
}

void select(int x, int y, int selected) {
    if (selected == 7) {
        if (num_s >= 4 && is_connected()) cnt++;
        return;
    }
    if (x == 5) return;
    int nx, ny;
    if (y == 4) nx = x + 1, ny = 0;
    else nx = x, ny = y + 1;
    sel[x][y] = true;
    if (team[x][y] == 'S') num_s++;
    select(nx, ny, selected + 1);
    sel[x][y] = false;
    if (team[x][y] == 'S') num_s--;
    select(nx, ny, selected);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < 5; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < 5; j++) team[i][j] = line[j];
    }
    select(0, 0, 0);
    cout << cnt << '\n';
}