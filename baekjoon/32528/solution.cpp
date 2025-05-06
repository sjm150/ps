#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, a, b;
    cin >> n >> a >> b;
    a--, b--;
    vector<int> l(n);
    for (auto &l: l) {
        cin >> l;
        l--;
    }

    vector<int> vst(n, -1), stk;
    vector<bool> cyc(n, false);
    function<void(int, int)> dfs = [&](int cur, int v) {
        vst[cur] = v;
        stk.push_back(cur);
        int nxt = l[cur];
        if (vst[nxt] < 0) {
            dfs(nxt, v);
        } else if (vst[nxt] == v) {
            for (int i = stk.size() - 1; i >= 0; i--) {
                cyc[stk[i]] = true;
                if (stk[i] == nxt) break;
            }
        }
        stk.pop_back();
    };
    for (int i = 0; i < n; i++) {
        if (vst[i] < 0) dfs(i, i);
    }

    auto solve = [&]() {
        if (a == b) return n % 2 ? 1 : -1;
        if (n % 2) return -1;
        while (!cyc[a] || !cyc[b]) {
            a = l[a];
            if (a == b) return 1;
            b = l[b];
            if (a == b) return -1;
        }
        if (l[a] == b) return 1;
        return 0;
    };

    int ans = solve();
    cout << (ans < 0 ? "first\n" : ans == 0 ? "draw\n" : "second\n");
}