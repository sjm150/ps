#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> edges(n);
    while (m--) {
        int p, q, r;
        cin >> p >> q >> r;
        edges[p - 1].emplace_back(r, q - 1);
    }
    vector<int> mx(n, 0), pth(n, -1);
    function<void(int)> dfs = [&](int cur) {
        for (auto [w, nxt]: edges[cur]) {
            if (nxt && !mx[nxt]) dfs(nxt);
            int v = w + (nxt ? mx[nxt] : 0);
            if (mx[cur] < v) {
                mx[cur] = v;
                pth[cur] = nxt;
            }
        }
    };
    dfs(0);
    cout << mx[0] << '\n';
    cout << 1 << ' ';
    for (int i = pth[0]; i != 0; i = pth[i]) cout << i + 1 << ' ';
    cout << 1 << '\n';
}