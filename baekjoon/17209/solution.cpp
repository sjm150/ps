#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<bool> vst;
int cnt[2];

void dfs(int cur, int o) {
    vst[cur] = true;
    cnt[o]++;
    for (int nxt: edges[cur]) {
        if (!vst[nxt]) dfs(nxt, 1 - o);
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    edges.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            if (c == '1') {
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
    }

    vst.resize(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (vst[i]) continue;
        cnt[0] = cnt[1] = 0;
        dfs(i, 0);
        ans += max(cnt[0], cnt[1]);
    }

    cout << ans << '\n';
}