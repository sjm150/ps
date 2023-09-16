#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int c[30001];
vector<int> edges[30001];
pi grp[30000];
int gidx;
int sumc[30000];

pi dfs(int cur) {
    int cnt = 1;
    int sum = c[cur];
    c[cur] = 0;
    for (int nxt: edges[cur]) {
        if (c[nxt] > 0) {
            auto [c, s] = dfs(nxt);
            cnt += c;
            sum += s;
        }
    }
    return {cnt, sum};
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> c[i];
    while (m--) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (c[i] > 0) grp[gidx++] = dfs(i);
    }
    sort(grp, grp + gidx);
    for (int g = 0; g < gidx; g++) {
        auto [cnt, sum] = grp[g];
        for (int i = k - 1; i >= cnt; i--) sumc[i] = max(sumc[i], sumc[i - cnt] + sum);
    }
    cout << sumc[k - 1] << '\n';
}