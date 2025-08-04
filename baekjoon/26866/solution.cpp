#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef struct State {
        int x, y, b = -1, l = -1, k = -1, f = -1, r = -1, t = -1;
        State(int x, int y): x(x), y(y) {}
        State(int x, int y, int b, int l, int k, int f, int r, int t):
            x(x), y(y), b(b), l(l), k(k), f(f), r(r), t(t) {}
        State gor() { return State(x, y + 1, r, b, k, f, t, l); }
        State gof() { return State(x + 1, y, f, l, b, t, r, k); }
        State gol() { return State(x, y - 1, l, t, k, f, b, r); }
        State gok() { return State(x - 1, y, k, l, t, b, r, f); }
        array<int, 8> key() { return {x, y, b, l, k, f, r, t}; }
        void print() {
            for (int a: {b, l, k, f, r, t}) cout << (a != -1 ? a : 0) << ' ';
            cout << '\n';
        }
    } stt_t;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> c(n, vector<int>(n));
        for (auto &c: c) {
            for (int &c: c) cin >> c;
        }

        set<array<int, 8>> hst;
        vector<stt_t> ss;
        vector<int> pre;
        queue<int> q;
        auto add = [&](stt_t s, int p) {
            if (s.x < 0 || s.x >= n || s.y < 0 || s.y >= n) return;
            if (s.b == -1) s.b = c[s.x][s.y];
            else if (s.b != c[s.x][s.y]) return;
            if (hst.find(s.key()) != hst.end()) return;
            hst.insert(s.key());
            ss.push_back(s);
            pre.push_back(p);
            q.push(ss.size() - 1);
        };

        add(State(0, 0), -1);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            add(ss[cur].gof(), cur);
            add(ss[cur].gor(), cur);
        }

        if (ss.back().x == n - 1 && ss.back().y == n - 1) {
            cout << "Yes\n";
            auto ans = ss.back();
            for (int i = ss.size() - 1; pre[i] != -1; i = pre[i]) {
                auto s = ss[i], p = ss[pre[i]];
                if (s.x == p.x + 1) ans = ans.gok();
                else ans = ans.gol();
            }
            ans.print();
        } else {
            cout << "No\n";
        }
    }
}