#include <iostream>
#include <vector>
#include <queue>
typedef long long lint;
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> edges(n + 1);
    while (m--) {
        int v1, v2; cin >> v1 >> v2;
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }
    vector<bool> vst(n + 1, false);
    queue<pair<int, int>> q;
    vst[1] = true;
    q.emplace(1, 0);
    int cnt = 0;
    while (!q.empty()) {
        auto [cur, d] = q.front(); q.pop();
        if (d < 2) {
            for (int nxt: edges[cur]) {
                if (!vst[nxt]) {
                    vst[nxt] = true;
                    q.emplace(nxt, d + 1);
                    cnt++;
                }
            }
        }
    }
    cout << cnt << '\n';
}