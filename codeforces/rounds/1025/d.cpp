#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int inf = 2e9 + 5;
    int t; cin >> t;
    while (t--) {
        int n, m, l;
        cin >> n >> m >> l;
        vector<int> a(l);
        for (int &a: a) cin >> a;
        vector<vector<int>> edges(n);
        while (m--) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        vector<vector<int>> dst(2, vector<int>(n, inf));
        queue<pair<int, int>> q;
        dst[0][0] = 0;
        q.emplace(0, 0);
        while (!q.empty()) {
            auto [p, cur] = q.front();
            q.pop();
            for (int nxt: edges[cur]) {
                if (dst[1 - p][nxt] == inf) {
                    dst[1 - p][nxt] = dst[p][cur] + 1;
                    q.emplace(1 - p, nxt);
                }
            }
        }

        int sum = accumulate(a.begin(), a.end(), 0);
        int mno = inf;
        for (int a: a) {
            if (a % 2 && mno > a) mno = a;
        }
        int osum, esum;
        if (sum % 2) {
            osum = sum;
            esum = osum - mno;
        } else {
            esum = sum;
            osum = esum - mno;
        }

        for (int i = 0; i < n; i++) cout << int(dst[0][i] <= esum || dst[1][i] <= osum);
        cout << '\n';
    }
}