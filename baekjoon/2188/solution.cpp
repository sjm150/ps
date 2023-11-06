#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> edges;
vector<int> mch, rmch;
vector<bool> vst;

bool bimch(int cur) {
    vst[cur] = true;
    for (int nxt: edges[cur]) {
        if (rmch[nxt] < 0 || (!vst[rmch[nxt]] && bimch(rmch[nxt]))) {
            mch[cur] = nxt;
            rmch[nxt] = cur;
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    edges.resize(n);
    mch.resize(n, -1), rmch.resize(m + 1, -1);
    vst.resize(n);
    for (int i = 0; i < n; i++) {
        int s; cin >> s;
        while (s--) {
            int j; cin >> j;
            edges[i].push_back(j);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        fill(vst.begin(), vst.end(), false);
        if (bimch(i)) cnt++;
    }
    cout << cnt << '\n';
}