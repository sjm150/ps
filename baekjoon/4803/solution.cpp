#include <iostream>
#include <vector>
typedef long long lint;
using namespace std;

vector<vector<int>> edges;
vector<bool> vst;
bool istree(int cur, int pre) {
    vst[cur] = true;
    for (int nxt: edges[cur]) {
        if (!vst[nxt]) {
            if (!istree(nxt, cur)) return false;
        } else if (nxt != pre) {
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t = 0;
    while (++t) {
        int n, m; cin >> n >> m;
        if (n == 0) break;
        edges = vector<vector<int>>(n + 1);
        vst = vector<bool>(n + 1, false);
        while (m--) {
            int v1, v2; cin >> v1 >> v2;
            edges[v1].push_back(v2);
            edges[v2].push_back(v1);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!vst[i]) {
                if (istree(i, 0)) cnt++;
            }
        }
        cout << "Case " << t << ": ";
        if (cnt == 0) cout << "No trees.\n";
        else if (cnt == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << cnt << " trees.\n";
    }
}