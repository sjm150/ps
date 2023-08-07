#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 123456789;

int t[501];
pair<int, int> vst[501];
int d[501][501], dt[501][501];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        vst[i] = {t[i], i};
        fill(d[i], d[i] + n + 1, inf);
        d[i][i] = 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) dt[i][j] = max(t[i], t[j]);
    sort(vst + 1, vst + n + 1);
    while (m--) {
        int a, b; cin >> a >> b;
        cin >> d[a][b];
        d[b][a] = d[a][b];
    }
    for (int k = 1; k <= n; k++) {
        int cur = vst[k].second;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][j] + dt[i][j] > d[i][cur] + d[cur][j] + max(dt[i][j], t[cur])) {
                    d[i][j] = d[i][cur] + d[cur][j];
                    dt[i][j] = max(dt[i][j], t[cur]);
                }
            }
        }
    }
    while (q--) {
        int s, e; cin >> s >> e;
        if (d[s][e] < inf) cout << d[s][e] + dt[s][e] << '\n';
        else cout << -1 << '\n';
    }
}