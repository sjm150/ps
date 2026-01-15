#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> w(n + 1, vector<int>(n + 1, -1));
    while (m--) {
        int u, v, d;
        cin >> u >> v >> d;
        w[u][v] = max(w[u][v], d);
    }

    int ans = -1;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    do {
        int pre = 0, sum = 0;
        bool ok = true;
        for (int cur: p) {
            if (w[pre][cur] < 0) {
                ok = false;
                break;
            }
            sum += w[pre][cur];
            pre = cur;
        }
        if (ok && w[pre][0] >= 0) ans = max(ans, sum + w[pre][0]);
    } while (next_permutation(p.begin(), p.end()));

    cout << ans << '\n';
}