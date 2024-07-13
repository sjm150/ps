#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, q; cin >> n >> q;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    int m; cin >> m;

    vector<vector<int>> chd(n + 1);
    vector<int> ind(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (p[i] == i) continue;
        chd[p[i]].push_back(i);
        ind[i]++;
    }

    int r = q - m;
    vector<string> out;
    function<void(int, int)> dfs = [&](int pre, int cur) {
        for (int nxt: chd[cur]) {
            out.push_back("1 " + to_string(nxt) + " " + to_string(cur));
            r--;
            dfs(cur, nxt);
        }
    };
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) dfs(0, i);
    }

    cout << n << ' ' << q << '\n';
    while (m--) {
        int v; cin >> v;
        cout << "2 " << v << '\n';
    }
    while (r--) {
        cout << "1 1 1\n";
    }
    reverse(out.begin(), out.end());
    for (auto &o: out) cout << o << '\n';
}