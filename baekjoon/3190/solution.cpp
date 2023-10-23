#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int n;
int grid[101][101];
int l, didx;
struct L { int x, dd; } ls[100];

bool oob(int x, int y) {
    return x <= 0 || n < x || y <= 0 || n < y;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int k; cin >> n >> k;
    while (k--) {
        int x, y; cin >> x >> y;
        grid[x][y] = 1;
    }
    int l; cin >> l;
    for (int i = 0; i < l; i++) {
        int x; char c; cin >> x >> c;
        if (c == 'L') ls[i] = L { x, -1 };
        else ls[i] = L { x, 1 };
    }

    int x, y, d, t;
    x = y = d = 1;
    t = 0;
    queue<pi> q;
    q.emplace(1, 1);

    while (true) {
        t++;
        x += dx[d], y += dy[d];
        if (oob(x, y) || grid[x][y] == 2) break;

        q.emplace(x, y);
        if (grid[x][y] == 0) {
            auto [tx, ty] = q.front(); q.pop();
            grid[tx][ty] = 0;
        }
        grid[x][y] = 2;

        if (didx < l && t == ls[didx].x) d = (d + ls[didx++].dd + 4) % 4;
    }

    cout << t << '\n';
}