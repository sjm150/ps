#include <iostream>
#include <vector>
typedef long long lint;
using namespace std;

vector<vector<int>> edges;
vector<bool> vst;
int cnt = 0;
void dfs(int cur) {
    vst[cur] = true;
    cnt++;
    for (int nxt: edges[cur]) {
        if (!vst[nxt]) dfs(nxt);
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    edges = vector<vector<int>>(n + 1);
    vst = vector<bool>(n + 1, false);
    while (m--) {
        int v1, v2; cin >> v1 >> v2;
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }
    dfs(1);
    cout << cnt - 1 << '\n';
}