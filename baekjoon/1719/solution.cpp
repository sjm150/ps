#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 123456789;

int t[201][201];
int nxt[201][201];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fill(t[i], t[i] + n + 1, inf);
        t[i][i] = 0;
        nxt[i][i] = i;
    }
    while (m--) {
        int u, v; cin >> u >> v;
        cin >> t[u][v];
        t[v][u] = t[u][v];
        nxt[u][v] = v;
        nxt[v][u] = u;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (t[i][j] > t[i][k] + t[k][j]) {
                    t[i][j] = t[i][k] + t[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                cout << "- ";
            } else {
                cout << nxt[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}