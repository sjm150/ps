#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> edges[100001];
bool vst[100001];
int maxd = 0;
int dfs(int cur) {
    vst[cur] = true;
    int max1 = 0, max2 = 0;
    for (auto [nxt, w]: edges[cur]) {
        if (!vst[nxt]) {
            int d = w + dfs(nxt);
            if (d > max1) {
                max2 = max1;
                max1 = d;
            } else if (d > max2) {
                max2 = d;
            }
        }
    }
    maxd = max(maxd, max1 + max2);
    return max1;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int u; cin >> u;
        while (true) {
            int v; cin >> v;
            if (v == -1) break;
            int w; cin >> w;
            edges[u].emplace_back(v, w);
            edges[v].emplace_back(u, w);
        }
    }
    dfs(1);
    cout << maxd << '\n';
}