#include <iostream>
#include <vector>
using namespace std;

vector<int> edges[10001];
int t[10001];
int tot[10001];
void dfs(int cur) {
    tot[cur] = t[cur];
    for (int nxt: edges[cur]) {
        if (tot[nxt] == 0) dfs(nxt);
        tot[cur] = max(tot[cur], tot[nxt] + t[cur]);
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int e; cin >> t[i] >> e;
        while (e--) {
            int v; cin >> v;
            edges[v].push_back(i);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (tot[i] == 0) {
            dfs(i);
            ans = max(ans, tot[i]);
        }
    }
    cout << ans << '\n';
}