#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, a, b; cin >> n >> a >> b;
    a--, b--;
    vector<string> conn(n);
    for (auto &s: conn) cin >> s;

    int ans = 0;
    vector<int> ag, bg;
    for (int i = 0; i < n; i++) {
        if (i == a || i == b) continue;
        if (conn[i][a] == 'Y' && conn[i][b] == 'Y') {
            ans++;
            continue;
        }
        if (conn[i][a] == 'Y') ag.push_back(i);
        else if (conn[i][b] == 'Y') bg.push_back(i);
    }
    int an = ag.size(), bn = bg.size();
    vector<vector<int>> edges(an);
    for (int i = 0; i < an; i++) {
        for (int j = 0; j < bn; j++) {
            if (conn[ag[i]][bg[j]] == 'Y') edges[i].push_back(j);
        }
    }

    vector<int> mch(an, -1), rmch(bn, -1);
    vector<bool> vst(an);
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

    for (int i = 0; i < an; i++) {
        fill(vst.begin(), vst.end(), false);
        ans += bpm(i);
    }
    cout << ans << '\n';
}