#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> edges[10001];
int maxd = 0;
int dfs(int cur) {
    int max1 = 0, max2 = 0;
    for (auto [nxt, w]: edges[cur]) {
        int d = dfs(nxt) + w;
        if (d > max1) {
            max2 = max1;
            max1 = d;
        } else if (d > max2) {
            max2 = d;
        }
    }
    maxd = max(maxd, max1 + max2);
    return max1;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int p, c, w; cin >> p >> c >> w;
        edges[p].emplace_back(c, w);
    }
    dfs(1);
    cout << maxd << '\n';
}