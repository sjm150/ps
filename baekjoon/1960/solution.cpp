#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x) pq.emplace(x, i);
    }
    vector<vector<bool>> grid(n, vector<bool>(n, false));
    bool poss = true;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        vector<pair<int, int>> r;
        while (x--) {
            if (pq.empty()) {
                poss = false;
                break;
            }
            auto [v, idx] = pq.top(); pq.pop();
            grid[idx][i] = true;
            if (v > 1) r.emplace_back(v - 1, idx);
        }
        if (!poss) break;
        for (auto &p: r) pq.emplace(p);
    }
    if (poss && pq.empty()) {
        cout << 1 << '\n';
        for (auto &g: grid) {
            for (auto g: g) cout << g;
            cout << '\n';
        }
    } else {
        cout << -1 << '\n';
    }
}