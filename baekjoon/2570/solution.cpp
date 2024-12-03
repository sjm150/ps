#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<bool>> blk(n, vector<bool>(n, false));
    while (m--) {
        int x, y; cin >> x >> y;
        blk[x - 1][y - 1] = true;
    }

    vector<vector<int>> vtx(n, vector<int>(n, -1));
    int vsz = 0, usz = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (blk[i][j] || vtx[i][j] >= 0) continue;
            for (int x = i, y = j; x < n && y < n && !blk[x][y]; x++, y++) vtx[x][y] = vsz;
            vsz++;
        }
    }
    vector<vector<int>> edges(vsz);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vtx[i][j] < 0) continue;
            for (int x = i, y = j; x < n && y >= 0 && !blk[x][y]; x++, y--) {
                edges[vtx[x][y]].push_back(usz);
                vtx[x][y] = -1;
            }
            usz++;
        }
    }

    vector<int> mch(vsz, -1), rmch(usz, -1);
    vector<bool> vst(vsz);
    function<bool(int)> bpm = [&](int cur) {
        vst[cur] = true;
        for (int nxt: edges[cur]) {
            if (rmch[nxt] < 0 || (!vst[rmch[nxt]] && bpm(rmch[nxt]))) {
                mch[cur] = nxt;
                rmch[nxt] = cur;
                return true;
            }
        }
        return false;
    };

    int ans = 0;
    for (int i = 0; i < vsz; i++) {
        fill(vst.begin(), vst.end(), false);
        ans += bpm(i);
    }
    cout << ans << '\n';
}