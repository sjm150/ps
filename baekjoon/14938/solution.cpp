#include <iostream>
using namespace std;
const int inf = 100000000;

int t[101];
int dst[101][101];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, r; cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dst[i][j] = inf;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        dst[i][i] = 0;
    }
    while (r--) {
        int a, b, l; cin >> a >> b >> l;
        dst[a][b] = dst[b][a] = l;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            if (dst[i][j] <= m) sum += t[j];
        }
        ans = max(ans, sum);
    }
    cout << ans << '\n';
}