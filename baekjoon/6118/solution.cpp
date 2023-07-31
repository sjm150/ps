#include <iostream>
#include <vector>
#include <queue>
typedef long long lint;
using namespace std;

vector<vector<int>> edges;
int dst[20001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    edges = vector<vector<int>>(n + 1);
    while (m--) {
        int v1, v2; cin >> v1 >> v2;
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }
    queue<int> q;
    dst[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt: edges[cur]) {
            if (dst[nxt] == 0) {
                dst[nxt] = dst[cur] + 1;
                q.push(nxt);
            }
        }
    }
    int maxd = 0, maxi = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (dst[i] > maxd) {
            maxd = dst[i];
            maxi = i;
            cnt = 1;
        } else if (dst[i] == maxd) {
            cnt++;
        }
    }
    cout << maxi << ' ' << maxd - 1 << ' ' << cnt << '\n';
}