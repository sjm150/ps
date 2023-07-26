#include <iostream>
#include <unordered_map>
using namespace std;

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m, k;
char grid[10][10];
unordered_map<string, int> cnts;

void dfs(int x, int y, string& cur) {
    cur.push_back(grid[x][y]);
    if (cnts.find(cur) != cnts.end()) cnts[cur]++;
    else cnts[cur] = 1;
    if (cur.length() < 5) {
        for (int i = 0; i < 8; i++) {
            int nx = (x + dx[i] + n) % n;
            int ny = (y + dy[i] + m) % m;
            dfs(nx, ny, cur);
        }
    }
    cur.pop_back();
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) grid[i][j] = s[j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            string s = "";
            dfs(i, j, s);
        }
    }
    while (k--) {
        string s; cin >> s;
        cout << cnts[s] << '\n';
    }
}