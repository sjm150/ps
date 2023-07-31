#include <iostream>
typedef long long lint;
using namespace std;
const int inf = 10000;

int dst[101][101];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            dst[i][j] = inf;
    for (int i = 1; i <= n; i++) dst[i][i] = 0;
    while (m--) {
        int v1, v2; cin >> v1 >> v2;
        dst[v1][v2] = dst[v2][v1] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
            }
        }
    }
    int minv = inf, mini = 0;
    for (int i = 1; i <= n; i++) {
        int v = 0;
        for (int j = 1; j <= n; j++) v += dst[i][j];
        if (v < minv) {
            minv = v;
            mini = i;
        }
    }
    cout << mini << '\n';
}