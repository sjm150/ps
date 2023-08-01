#include <iostream>
#include <vector>
typedef long long lint;
using namespace std;

vector<int> edges[100001];
bool vst[100001];
void dfs(int cur) {
    vst[cur] = true;
    for (int nxt: edges[cur]) {
        if (!vst[nxt]) dfs(nxt);
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    int k = 0;
    for (int i = 1; i <= n; i++) {
        if (!vst[i]) {
            dfs(i);
            k++;
        }
    }
    cout << m - n + 2 * k - 1 << '\n';
}