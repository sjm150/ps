#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 123456789;

int edges[201][201], dst[201][201];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cout.precision(1); cout << fixed;
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fill(dst[i], dst[i] + n + 1, inf);
        dst[i][i] = 0;
    }
    while (m--) {
        int s, e, l; cin >> s >> e >> l;
        edges[s][e] = edges[e][s] = max(edges[s][e], l);
        dst[s][e] = dst[e][s] = min(dst[s][e], l);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
    int minm = inf;
    for (int i = 1; i <= n; i++) {
        int maxt = 0;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (edges[k][j]) maxt = max(maxt, dst[i][j] + dst[i][k] + edges[k][j]);
            }
        }
        if (maxt) minm = min(minm, maxt);
    }
    cout << double(minm) / 2 << '\n';
}