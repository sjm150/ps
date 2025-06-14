#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef pair<int, int> pi;
    const int mx = 1 << 10;
    int n, m;
    cin >> n >> m;
    vector<vector<pi>> edges(n);
    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[a - 1].emplace_back(w, b - 1);
    }

    vector<vector<bool>> vst(n, vector<bool>(mx, false));
    queue<pair<int, int>> q;
    vst[0][0] = true;
    q.emplace(0, 0);
    while (!q.empty()) {
        auto [cur, b] = q.front();
        q.pop();
        for (auto [w, nxt]: edges[cur]) {
            if (!vst[nxt][w ^ b]) {
                vst[nxt][w ^ b] = true;
                q.emplace(nxt, w ^ b);
            }
        }
    }

    int mn = find(vst[n - 1].begin(), vst[n - 1].end(), true) - vst[n - 1].begin();
    cout << (mn < mx ? mn : -1) << '\n';
}