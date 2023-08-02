#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> edges[32001];
int indeg[32001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        indeg[b]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << ' ';
        for (int v: edges[u]) {
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }
    cout << '\n';
}