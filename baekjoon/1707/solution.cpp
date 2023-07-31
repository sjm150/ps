#include <iostream>
#include <vector>
#include <algorithm>
typedef long long lint;
using namespace std;

vector<vector<int>> edges;
int g[20001];
bool dfs(int cur, int grp) {
    g[cur] = grp;
    for (int nxt: edges[cur]) {
        if (g[nxt] == 0) {
            if (!dfs(nxt, -grp)) return false;
        } else if (g[nxt] == g[cur]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int k; cin >> k;
    while (k--) {
        int v, e; cin >> v >> e;
        edges = vector<vector<int>>(v + 1);
        fill(g, g + v + 1, 0);
        while (e--) {
            int v1, v2; cin >> v1 >> v2;
            edges[v1].push_back(v2);
            edges[v2].push_back(v1);
        }
        bool bipart = true;
        for (int i = 1; i <= v; i++) {
            if (g[i] == 0) {
                if (!dfs(i, 1)) {
                    bipart = false;
                    break;
                }
            }
        }
        if (bipart) cout << "YES\n";
        else cout << "NO\n";
    }
}