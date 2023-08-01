#include <iostream>
#include <vector>
typedef long long lint;
using namespace std;

vector<int> edges[100001];
int tsize[100001];
int dfs(int root) {
    tsize[root] = 1;
    for (int nxt: edges[root]) {
        if (tsize[nxt] == 0) tsize[root] += dfs(nxt);
    }
    return tsize[root];
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, r, q; cin >> n >> r >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(r);
    while (q--) {
        int u; cin >> u;
        cout << tsize[u] << '\n';
    }
}