#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto &a: a) {
        for (int &a: a) cin >> a;
    }

    vector<vector<int>> grp;
    vector<bool> vst(n, false);
    function<void(int)> dfs = [&](int cur) {
        vst[cur] = true;
        grp.back().push_back(cur);
        for (int i = 0; i < n; i++) {
            if (a[cur][i] == 0 && !vst[i]) dfs(i);
        }
    };
    for (int i = 0; i < n; i++) {
        if (!vst[i]) {
            grp.emplace_back();
            dfs(i);
        }
    }

    bool ok = true;
    for (auto &g: grp) {
        int sz = g.size();
        if (sz == 1) ok = false;
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if (a[g[i]][g[j]]) {
                    ok = false;
                    break;
                }
            }
        }
    }
    if (!ok) grp.clear();
    cout << grp.size() << '\n';
    for (auto &g: grp) {
        for (int g: g) cout << g + 1 << ' ';
        cout << '\n';
    }
}