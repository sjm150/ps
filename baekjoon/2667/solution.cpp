#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int n;
char map[25][25];
bool vst[25][25];
int dfs(int x, int y) {
    vst[x][y] = true;
    int cnt = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n &&
            map[nx][ny] == '1' && !vst[nx][ny]) {
            cnt += dfs(nx, ny);
        }
    }
    return cnt;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string line; cin >> line;
        for (int j = 0; j < n; j++) map[i][j] = line[j];
    }
    vector<int> cnts;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == '1' && !vst[i][j]) cnts.push_back(dfs(i, j));
        }
    }
    sort(cnts.begin(), cnts.end());
    cout << cnts.size() << '\n';
    for (int cnt: cnts) cout << cnt << '\n';
}