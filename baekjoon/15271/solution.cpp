#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int sz = n / 2 + 1;
    vector<vector<int>> edges(sz);
    while (m--) {
        int u, v; cin >> u >> v;
        if ((u + v) % 2 == 0) continue;
        if (u % 2) swap(u, v);
        u = (u - 1) / 2;
        v = (v - 1) / 2;
        edges[u].push_back(v);
    }

    vector<int> mch(sz, -1), rmch(sz, -1);
    vector<bool> vst(sz);
    function<bool(int)> bpm = [&](int cur) {
        vst[cur] = true;
        for (int nxt: edges[cur]) {
            if (rmch[nxt] == cur) continue;
            if (rmch[nxt] < 0 || (!vst[rmch[nxt]] && bpm(rmch[nxt]))) {
                mch[cur] = nxt;
                rmch[nxt] = cur;
                return true;
            }
        }
        return false;
    };

    int cnt = 0;
    for (int i = 0; i < sz; i++) {
        fill(vst.begin(), vst.end(), false);
        if (bpm(i)) cnt++;
    }
    cout << cnt * 2 + (cnt * 2 < n) << '\n';
}