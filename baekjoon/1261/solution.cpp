#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> ti;
const int inf = 123456789;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int rooms[100][100];
int dst[100][100];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int m, n; cin >> m >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) rooms[i][j] = s[j] - '0';
        fill(dst[i], dst[i] + m, inf);
    }
    priority_queue<ti, vector<ti>, greater<ti>> pq;
    dst[0][0] = 0;
    pq.emplace(0, 0, 0);
    while (!pq.empty()) {
        auto [d, x, y] = pq.top(); pq.pop();
        if (d != dst[x][y]) continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m &&
                dst[nx][ny] > dst[x][y] + rooms[nx][ny]) {
                dst[nx][ny] = dst[x][y] + rooms[nx][ny];
                pq.emplace(dst[nx][ny], nx, ny);
            }
        }
    }
    cout << dst[n - 1][m - 1] << '\n';
}