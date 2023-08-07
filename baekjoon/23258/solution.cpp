#include <iostream>
using namespace std;
const int inf = 123456789;

int dst[301][301][301];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int d; cin >> d;
            if (i != j && d == 0) dst[0][i][j] = inf;
            else dst[0][i][j] = d;
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dst[k][i][j] = min(dst[k - 1][i][j], dst[k - 1][i][k] + dst[k - 1][k][j]);
    while (q--) {
        int c, s, e; cin >> c >> s >> e;
        if (dst[c - 1][s][e] < inf) cout << dst[c - 1][s][e] << '\n';
        else cout << -1 << '\n';
    }
}