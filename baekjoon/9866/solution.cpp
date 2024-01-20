#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int inf = 1e9;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k, q; cin >> n >> m >> k >> q;
    vector<vector<pi>> edges(n + 1), redges(n + 1);
    while (m--) {
        int u, v, d; cin >> u >> v >> d;
        edges[u].emplace_back(d, v);
        redges[v].emplace_back(d, u);
    }
    vector<int> frm(k), hub(n + 1, -1);
    for (int i = 0; i < k; i++) {
        cin >> frm[i];
        hub[frm[i]] = i;
    }

    vector<vector<int>> hdst(k, vector<int>(k, inf)), hrdst(k, vector<int>(k, inf));
    for (int i = 0; i < k; i++) hdst[i][i] = hrdst[i][i] = 0;
    for (int i = 1; i <= n; i++) {
        if (hub[i] < 0) continue;
        for (auto &[d, nxt]: edges[i]) {
            if (hub[nxt] < 0) {
                for (auto &[nd, nnxt]: edges[nxt]) {
                    hdst[hub[i]][hub[nnxt]] = min(hdst[hub[i]][hub[nnxt]], d + nd);
                    hrdst[hub[nnxt]][hub[i]] = min(hrdst[hub[nnxt]][hub[i]], d + nd);
                }
            } else {
                hdst[hub[i]][hub[nxt]] = min(hdst[hub[i]][hub[nxt]], d);
                hrdst[hub[nxt]][hub[i]] = min(hrdst[hub[nxt]][hub[i]], d);
            }
        }
    }

    for (int l = 0; l < k; l++) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (hdst[i][j] > hdst[i][l] + hdst[l][j]) hdst[i][j] = hdst[i][l] + hdst[l][j];
                if (hrdst[i][j] > hrdst[i][l] + hrdst[l][j]) hrdst[i][j] = hrdst[i][l] + hrdst[l][j];
            }
        }
    }

    vector<vector<int>> dst(n + 1), rdst(n + 1);
    int cnt = 0;
    long long sum = 0;
    while (q--) {
        int a, b; cin >> a >> b;
        if (dst[a].empty()) {
            if (hub[a] < 0) {
                dst[a].resize(k, inf);
                for (auto &[d, nxt]: edges[a]) {
                    for (int i = 0; i < k; i++) {
                        if (dst[a][i] > d + hdst[hub[nxt]][i]) dst[a][i] = d + hdst[hub[nxt]][i];
                    }
                }
            } else {
                dst[a] = hdst[hub[a]];
            }
        }
        if (rdst[b].empty()) {
            if (hub[b] < 0) {
                rdst[b].resize(k, inf);
                for (auto &[d, nxt]: redges[b]) {
                    for (int i = 0; i < k; i++) {
                        if (rdst[b][i] > d + hrdst[hub[nxt]][i]) rdst[b][i] = d + hrdst[hub[nxt]][i];
                    }
                }
            } else {
                rdst[b] = hrdst[hub[b]];
            }
        }
        int mind = inf;
        for (int i = 0; i < k; i++) mind = min(mind, dst[a][i] + rdst[b][i]);
        if (mind < inf) {
            cnt++;
            sum += mind;
        }
    }

    cout << cnt << '\n' << sum << '\n';
}