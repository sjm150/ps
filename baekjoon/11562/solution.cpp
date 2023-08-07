#include <iostream>
using namespace std;
const int inf = 123456789;

int req[251][251];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            req[i][j] = inf;
    for (int i = 1; i <= n; i++) req[i][i] = 0;
    while (m--) {
        int u, v, b; cin >> u >> v >> b;
        if (b == 0) req[u][v] = 0, req[v][u] = 1;
        else req[u][v] = req[v][u] = 0;
    }
    for (int k = 1; k <= n; k++)
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= n; i++)
                if (req[i][j] > req[i][k] + req[k][j])
                    req[i][j] = req[i][k] + req[k][j];
    int k; cin >> k;
    while (k--) {
        int s, e; cin >> s >> e;
        cout << req[s][e] << '\n';
    }
}