#include <iostream>
#include <vector>
typedef long long lint;
using namespace std;

vector<vector<int>> edges;
int prnt[100001];
void dfs(int cur) {
    for (int nxt: edges[cur]) {
        if (prnt[nxt] == 0) {
            prnt[nxt] = cur;
            dfs(nxt);
        }
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    edges = vector<vector<int>>(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int v1, v2; cin >> v1 >> v2;
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }
    prnt[1] = 1;
    dfs(1);
    for (int i = 2; i <= n; i++) cout << prnt[i] << '\n';
}