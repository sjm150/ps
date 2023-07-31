#include <iostream>
#include <vector>
#include <algorithm>
typedef long long lint;
using namespace std;

vector<vector<int>> edges;
bool vst[10001];
int c[10001];
int dfs(int cur) {
    vst[cur] = true;
    int cnt = 1;
    for (int nxt: edges[cur]) {
        if (!vst[nxt]) cnt += dfs(nxt);
    }
    return cnt;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    edges = vector<vector<int>>(n + 1);
    while (m--) {
        int a, b; cin >> a >> b;
        edges[b].push_back(a);
    }
    int maxc = 0;
    for (int i = 1; i <= n; i++) {
        fill(vst, vst + n + 1, false);
        c[i] = dfs(i);
        maxc = max(maxc, c[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (c[i] == maxc) cout << i << ' ';
    }
    cout << '\n';
}