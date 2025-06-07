#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef tuple<int, int, int> ti;
    typedef struct Djset {
        vector<int> p;
        Djset(int n): p(n) { iota(p.begin(), p.end(), 0); }
        void add() { p.push_back(p.size()); }
        int find(int x) {
            if (p[x] == x) return x;
            return p[x] = find(p[x]);
        }
        void uni(int u, int v) {
            u = find(u), v = find(v);
            p[u] = v;
        }
        bool conn(int u, int v) { return find(u) == find(v); }
    } djs_t;

    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> xy(n);
    for (auto &[x, y]: xy) cin >> x >> y;

    djs_t djs(n);
    priority_queue<ti, vector<ti>, greater<ti>> pq;
    auto dst = [&](int i, int j) {
        auto [xi, yi] = xy[i];
        auto [xj, yj] = xy[j];
        return abs(xi - xj) + abs(yi - yj);
    };
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) pq.emplace(dst(i, j), i, j);
    }

    while (q--) {
        int c;
        cin >> c;
        if (c == 1) {
            int a, b;
            cin >> a >> b;
            xy.emplace_back(a, b);
            n++;
            djs.add();
            for (int i = 0; i < n - 1; i++) pq.emplace(dst(i, n - 1), i, n - 1);
        } else if (c == 2) {
            while (!pq.empty()) {
                auto [d, i, j] = pq.top();
                if (djs.conn(i, j)) pq.pop();
                else break;
            }
            if (pq.empty()) {
                cout << -1 << '\n';
            } else {
                int mn = get<0>(pq.top());
                while (!pq.empty() && get<0>(pq.top()) == mn) {
                    auto [d, i, j] = pq.top();
                    pq.pop();
                    djs.uni(i, j);
                }
                cout << mn << '\n';
            }
        } else {
            int u, v;
            cin >> u >> v;
            cout << (djs.conn(u - 1, v - 1) ? "Yes\n" : "No\n");
        }
    }
}