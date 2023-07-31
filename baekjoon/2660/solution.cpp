#include <iostream>
typedef long long lint;
using namespace std;
const int inf = 1000000;

int dst[51][51];
int d[51];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dst[i][j] = inf;
        }
    }
    for (int i = 1; i <= n; i++) dst[i][i] = 0;
    while (true) {
        int v1, v2; cin >> v1 >> v2;
        if (v1 == -1) break;
        dst[v1][v2] = dst[v2][v1] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
            }
        }
    }
    int mind = inf, cnt = 0;
    for (int i = 1; i <= n; i++) {
        d[i] = 0;
        for (int j = 1; j <= n; j++) d[i] = max(d[i], dst[i][j]);
        if (d[i] < mind) {
            mind = d[i];
            cnt = 1;
        } else if (d[i] == mind) {
            cnt++;
        }
    }
    cout << mind << ' ' << cnt << '\n';
    for (int i = 1; i <= n; i++) {
        if (mind == d[i]) cout << i << ' ';
    }
    cout << '\n';
}