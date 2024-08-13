#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int k; cin >> k;
    vector<bool> vst(1e4, false);
    const int dx[] = {-2, -1, -2, 1, -1, 2, 1, 2};
    const int dy[] = {-1, -2, 1, -2, 2, -1, 2, 1};
    int x = 1, y = 1;
    auto num = [](int x, int y) { return (x + y - 1) * (x + y - 2) / 2 + x; };
    while (k--) {
        vst[num(x, y)] = true;
        bool ok = false;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx <= 0 || ny <= 0) continue;
            if (vst[num(nx, ny)]) continue;
            x = nx, y = ny;
            ok = true;
            break;
        }
        if (!ok) break;
    }
    cout << num(x, y) << '\n';
}