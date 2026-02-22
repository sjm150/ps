#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, a, b, m;
    cin >> n >> a >> b >> m;
    a--, b--;
    vector<vector<int>> edges(n);
    while (m--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    vector<int> dst(n, -1);
    function<void(int)> dfs = [&](int cur) {
        for (int nxt: edges[cur]) {
            if (dst[nxt] < 0) {
                dst[nxt] = dst[cur] + 1;
                dfs(nxt);
            }
        }
    };
    dst[a] = 0;
    dfs(a);
    cout << dst[b] << '\n';
}