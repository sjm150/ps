#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> edges(n);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        while (k--) {
            int w; cin >> w;
            edges[i].push_back(w - 1);
        }
    }
    vector<int> mch(m, -1);
    vector<bool> vst(n);
    function<bool(int)> match = [&](int cur) {
        vst[cur] = true;
        for (int nxt: edges[cur]) {
            int m = mch[nxt];
            if (m < 0 || (!vst[m] && match(m))) {
                mch[nxt] = cur;
                return true;
            }
        }
        return false;
    };
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        fill(vst.begin(), vst.end(), false);
        if (match(i)) cnt++;
    }
    cout << cnt << '\n';
}