#include <iostream>
#include <vector>
using namespace std;

int d[1001];
vector<vector<int>> edges;
int tot[1001];
int dfs(int cur) {
    for (int nxt: edges[cur]) {
        if (tot[nxt] == 0) dfs(nxt);
        if (tot[nxt] > 0) tot[cur] = max(tot[cur], tot[nxt] + d[cur]);
    }
    if (tot[cur] == 0) tot[cur] = -1;
    return tot[cur];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        edges = vector<vector<int>>(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> d[i];
            tot[i] = 0;
        }
        while (k--) {
            int x, y; cin >> x >> y;
            edges[x].push_back(y);
        }
        int w; cin >> w;
        tot[w] = d[w];
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (tot[i] == 0) dfs(i);
            ans = max(ans, tot[i]);
        }
        cout << ans << '\n';
    }
}