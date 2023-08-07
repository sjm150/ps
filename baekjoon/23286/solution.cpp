#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 123456789;

int h[301][301];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, t; cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        fill(h[i], h[i] + n + 1, inf);
        h[i][i] = 0;
    }
    while (m--) {
        int u, v; cin >> u >> v;
        cin >> h[u][v];
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                h[i][j] = min(h[i][j], max(h[i][k], h[k][j]));
    while (t--) {
        int s, e; cin >> s >> e;
        if (h[s][e] < inf) cout << h[s][e] << '\n';
        else cout << -1 << '\n';
    }
}