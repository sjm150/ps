#include <iostream>
using namespace std;
const int inf = 100000000;

int w[101][101];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            w[i][j] = inf;
        }
    }
    for (int i = 1; i <= n; i++) w[i][i] = 0;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        w[a][b] = min(w[a][b], c);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (w[i][j] < inf) cout << w[i][j] << ' ';
            else cout << 0 << ' ';
        }
        cout << '\n';
    }
}