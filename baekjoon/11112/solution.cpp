#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef array<array<int, 3>, 3> g_t;
    auto enc = [](const g_t &arr) {
        int v = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                v = v * 9 + arr[i][j];
            }
        }
        return v;
    };
    auto dec = [](int v) {
        g_t arr;
        for (int i = 2; i >= 0; i--) {
            for (int j = 2; j >= 0; j--) {
                arr[i][j] = v % 9;
                v /= 9;
            }
        }
        return arr;
    };

    int ev = enc({array{1, 2, 3}, {4, 5, 6}, {7, 8, 0}});
    unordered_map<int, int> dst;
    queue<int> q;
    dst[ev] = 0;
    q.push(ev);

    const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        g_t cur = dec(v);
        int x = 0, y = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (cur[i][j] == 0) {
                    x = i, y = j;
                    break;
                }
            }
            if (cur[x][y] == 0) break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx > 2 || ny < 0 || ny > 2) continue;
            swap(cur[x][y], cur[nx][ny]);
            int nv = enc(cur);
            swap(cur[x][y], cur[nx][ny]);
            if (dst.find(nv) == dst.end()) {
                dst[nv] = dst[v] + 1;
                q.push(nv);
            }
        }
    }

    int t; cin >> t;
    while (t--) {
        g_t s;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                char c; cin >> c;
                if (c == '#') s[i][j] = 0;
                else s[i][j] = c - '0';
            }
        }
        int sv = enc(s);
        if (dst.find(sv) != dst.end()) cout << dst[sv] << '\n';
        else cout << "impossible\n";
    }
}