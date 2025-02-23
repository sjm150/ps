#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for (int &v: v) cin >> v;
    vector<vector<int>> edges(n);
    for (int i = 1; i < n; i++) {
        int p; cin >> p;
        edges[p - 1].push_back(i);
    }

    vector<int> h(n);
    vector<vector<int>> anc(1, vector<int>(n, -1));
    vector<ll> f(n, 0), sum(n);
    h[0] = 0;
    function<void(int)> dfs = [&](int cur) {
        sum[cur] = v[cur];
        for (int nxt: edges[cur]) {
            h[nxt] = h[cur] + 1;
            anc[0][nxt] = cur;
            dfs(nxt);
            sum[cur] += sum[nxt];
            f[cur] += sum[nxt] + f[nxt];
        }
    };
    dfs(0);
    int sz = log2(*max_element(h.begin(), h.end())) + 1;
    anc.resize(sz, vector<int>(n, -1));
    for (int i = 1; i < sz; i++) {
        for (int j = 0; j < n; j++) {
            anc[i][j] = (anc[i - 1][j] < 0 ? -1 : anc[i - 1][anc[i - 1][j]]);
        }
    }

    while (q--) {
        int x, y; cin >> x >> y;
        x--, y--;
        int d = x;
        for (int i = sz; i >= 0; i--) {
            if (h[d] - h[y] > (1 << i)) d = anc[i][d];
        }
        cout << f[y] + sum[d] - sum[x] - v[x] * ll(h[x] - h[d]) << '\n';
    }
}