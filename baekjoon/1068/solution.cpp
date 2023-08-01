#include <iostream>
#include <vector>
typedef long long lint;
using namespace std;

vector<int> childs[50];
int parent[50];
int cnt[50];
int dfs(int cur) {
    if (childs[cur].empty()) cnt[cur]++;
    for (int nxt: childs[cur]) cnt[cur] += dfs(nxt);
    return cnt[cur];
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int r = 0;
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        if (p == -1) r = i;
        else childs[p].push_back(i);
        parent[i] = p;
    }
    dfs(r);
    int u; cin >> u;
    int ans = cnt[r] - cnt[u];
    if (parent[u] >= 0 && childs[parent[u]].size() == 1) ans++;
    cout << ans << '\n';
}