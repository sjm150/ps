#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> edges(n * 2);
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        while (c--) {
            int w; cin >> w;
            w--;
            edges[i].push_back(w);
            edges[i + n].push_back(w);
        }
    }

    vector<int> mch(n * 2, -1), rmch(m, -1);
    vector<bool> vst(n * 2);
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

    int cnt = 0;
    for (int i = 0; i < n * 2; i++) {
        fill(vst.begin(), vst.end(), false);
        if (bpm(i)) cnt++;
    }
    cout << cnt << '\n';
}