#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> edges[101];
int req[101][101];
bool vst[101];
void dfs(int cur) {
    vst[cur] = true;
    if (edges[cur].empty()) req[cur][cur] = 1;
    for (auto [nxt, k]: edges[cur]) {
        if (!vst[nxt]) dfs(nxt);
        for (int i = 1; i <= n; i++) req[cur][i] += req[nxt][i] * k;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int m; cin >> n >> m;
    while (m--) {
        int x, y, k; cin >> x >> y >> k;
        edges[x].emplace_back(y, k);
    }
    dfs(n);
    for (int i = 1; i < n; i++) {
        if (req[n][i] > 0) cout << i << ' ' << req[n][i] << '\n';
    }
}