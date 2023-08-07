#include <iostream>
using namespace std;
const int inf = 123456789;

int c[401][401];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int v, e; cin >> v >> e;
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
            c[i][j] = inf;
    while (e--) {
        int a, b; cin >> a >> b;
        cin >> c[a][b];
    }
    for (int k = 1; k <= v; k++)
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
                if (c[i][j] > c[i][k] + c[k][j])
                    c[i][j] = c[i][k] + c[k][j];
    int mind = inf;
    for (int i = 1; i <= v; i++) mind = min(mind, c[i][i]);
    if (mind < inf) cout << mind << '\n';
    else cout << -1 << '\n';
}