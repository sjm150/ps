#include <iostream>
using namespace std;
const int inf = 123456789;

int t[201][201];
int c[200];
int x[200];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        t[i][j] = inf;
    for (int i = 1; i <= n; i++) t[i][i] = 0;
    while (m--) {
        int a, b; cin >> a >> b;
        cin >> t[a][b];
    }
    int k; cin >> k;
    for (int i = 0; i < k; i++) cin >> c[i];
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                t[i][j] = min(t[i][j], t[i][k] + t[k][j]);
            }
        }
    }
    int minm = inf;
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        int maxt = 0;
        bool able = true;
        for (int j = 0; j < n; j++) {
            if (t[i][c[j]] < inf && t[c[j]][i] < inf) {
                maxt = max(maxt, t[i][c[j]] + t[c[j]][i]);
            } else {
                able = false;
                break;
            }
        }
        if (able) {
            if (maxt < minm) {
                minm = maxt;
                x[0] = i;
                idx = 1;
            } else if (maxt == minm) {
                x[idx++] = i;
            }
        }
    }
    for (int i = 0; i < idx; i++) cout << x[i] << ' ';
    cout << '\n';
}