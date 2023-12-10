#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> c;
vector<int> p, h;

void dfs(int pre, int cur) {
    h[cur] = h[pre] + 1;
    for (int nxt: c[cur]) {
        if (pre == nxt) continue;
        dfs(cur, nxt);
    }
}

int lca(int a, int b) {
    if (h[a] < h[b]) return lca(b, a);
    int dh = h[a] - h[b];
    while (dh--) a = p[a];
    while (a != b) {
        a = p[a];
        b = p[b];
    }
    return a;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        c = vector<vector<int>>(n + 1);
        p = h = vector<int>(n + 1, 0);
        for (int i = 0; i < n - 1; i++) {
            int a, b; cin >> a >> b;
            c[a].push_back(b);
            p[b] = a;
        }

        int r = 1;
        while (p[r]) r = p[r];
        dfs(0, r);

        int a, b; cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}