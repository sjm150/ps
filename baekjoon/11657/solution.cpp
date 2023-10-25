#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

const ll inf = 1e18;
const ll thr = inf / 2;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<pi>> edges(n + 1);
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        edges[a].emplace_back(c, b);
    }

    vector<ll> dst(n + 1, inf);
    vector<queue<int>> q(2);
    int qcur = 0, qnxt = 1;
    dst[1] = 0;
    q[qcur].push(1);
    for (int i = 0; i < n; i++) {
        while (!q[qcur].empty()) {
            int cur = q[qcur].front(); q[qcur].pop();
            for (auto [w, nxt]: edges[cur]) {
                if (dst[nxt] > w + dst[cur]) {
                    dst[nxt] = w + dst[cur];
                    q[qnxt].push(nxt);
                }
            }
        }
        qcur = 1 - qcur;
        qnxt = 1 - qnxt;
    }

    bool relaxed = false;
    while (!q[qcur].empty()) {
        if (dst[q[qcur].front()] < thr) {
            relaxed = true;
            break;
        }
        q[qcur].pop();
    }

    if (relaxed) {
        cout << -1 << '\n';
    } else {
        for (int i = 2; i <= n; i++) {
            if (dst[i] < thr) cout << dst[i] << '\n';
            else cout << -1 << '\n';
        }
    }
}