#include <iostream>
typedef long long lint;
using namespace std;

int cmp[100][100];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        cmp[a][b] = 1;
        cmp[b][a] = -1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cmp[i][j] == 0) {
                    if (cmp[i][k] < 0 && cmp[k][j] < 0) cmp[i][j] = -1;
                    else if (cmp[i][k] > 0 && cmp[k][j] > 0) cmp[i][j] = 1;
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int h = 0, l = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (cmp[i][j] < 0) h++;
            else if (cmp[i][j] > 0) l++;
        }
        int lim = (n - 1) / 2;
        if (h > lim || l > lim) cnt++;
    }
    cout << cnt << '\n';
}