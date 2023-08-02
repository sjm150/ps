#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> edges[1001];
int indeg[1001];
int order[1001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int k, u; cin >> k >> u;
        k--;
        while (k--) {
            int v; cin >> v;
            edges[u].push_back(v);
            indeg[v]++;
            u = v;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) q.push(i);
    }
    int idx = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order[idx++] = u;
        for (int v: edges[u]) {
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }
    if (idx == n) {
        for (int i = 0; i < n; i++) cout << order[i] << ' ';
        cout << '\n';
    } else {
        cout << 0 << '\n';
    }
}