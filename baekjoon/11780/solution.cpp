#include <iostream>
using namespace std;
const int inf = 100000000;

int w[101][101];
int nxt[101][101];
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
        if (w[a][b] > c) {
            w[a][b] = c;
            nxt[a][b] = b;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (w[i][j] > w[i][k] + w[k][j]) {
                    w[i][j] = w[i][k] + w[k][j];
                    nxt[i][j] = nxt[i][k];
                }
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
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || w[i][j] >= inf) {
                cout << 0 << '\n';
                continue;
            }
            string out = "";
            int cnt = 1, cur = i;
            while (cur != j) {
                out += to_string(cur) + " ";
                cnt++;
                cur = nxt[cur][j];
            }
            out += to_string(j);
            cout << cnt << ' ' << out << '\n';
        }
    }
}