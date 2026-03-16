#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int sz = 11814485 + 1;
    vector<vector<int>> ok(11, vector<int>(sz, 0));
    for (int i = 2; i < 11; i++) ok[i][1] = 1;
    function<void(int, int)> dfs = [&](int cur, int b) {
        ok[b][cur] = -1;
        int nxt = 0;
        for (int i = cur; i; i /= b) nxt += (i % b) * (i % b);
        if (!ok[b][nxt]) dfs(nxt, b);
        if (ok[b][nxt] > 0) ok[b][cur] = 1;
    };
    vector<int> v(512, sz);
    for (int i = 2; i < sz; i++) {
        int bm = 0;
        for (int b = 2; b < 11; b++) {
            if (!ok[b][i]) dfs(i, b);
            if (ok[b][i] > 0) bm |= 1 << (b - 2);
        }
        v[bm] = min(v[bm], i);
    }
    for (int i = 511; i; i--) {
        for (int j = i; j; j = ((j - 1) & i)) v[j] = min(v[j], v[i]);
    }
    for (int v: v) cout << v << ',';
    // for (int i = 1; i < 512; i++) {
    //     for (int b = 2; b < 11; b++) {
    //         if (i & (1 << (b - 2))) {
    //             cout << b << ' ';
    //             assert(ok[b][v[i]] > 0);
    //         }
    //     }
    //     cout << ": " << v[i] << '\n';
    // }
}