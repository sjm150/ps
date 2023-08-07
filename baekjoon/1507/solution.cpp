#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;
const int inf = 123456789;

int fin[20][20], cur[20][20];
tuple<int, int, int> paths[190];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> fin[i][j];
    int idx = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            paths[idx++] = {fin[i][j], i, j};
    sort(paths, paths + idx);
    for (int i = 0; i < n; i++) {
        fill(cur[i], cur[i] + n, inf);
        cur[i][i] = 0;
    }
    bool able = true;
    int sum = 0;
    for (int i = 0; i < idx; i++) {
        auto [d, u, v] = paths[i];
        if (d > cur[u][v]) {
            able = false;
            break;
        } else if (d < cur[u][v]) {
            sum += d;
            cur[u][v] = cur[v][u] = d;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    cur[i][j] = cur[j][i] = min(cur[i][j], min(cur[i][v] + cur[u][j], cur[i][u] + cur[v][j]) + d);
                }
            }
        }
    }
    if (able) cout << sum << '\n';
    else cout << -1 << '\n';
}