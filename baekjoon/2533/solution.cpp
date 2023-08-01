#include <iostream>
#include <vector>
using namespace std;

vector<int> edges[1000001];
int cnt;
bool dfs(int cur, int pre) {
    bool sel = false;
    for (int nxt: edges[cur]) {
        if (nxt == pre) continue;
        if (!dfs(nxt, cur)) sel = true;
    }
    if (sel) cnt++;
    return sel;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1, 0);
    cout << cnt << '\n';
}