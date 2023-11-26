#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct Vec {
    int x, y;
    Vec(): x(0), y(0) {}
    Vec(int x, int y): x(x), y(y) {}

    void sub(const Vec& v) {
        x -= v.x;
        y -= v.y;
    }
    
    void swap(Vec& v) {
        int tx = x, ty = y;
        x = v.x, y = v.y;
        v.x = tx, v.y = ty;
    }

    ll cross(const Vec& v) { return ll(x) * v.y - ll(v.x) * y; }

    Vec operator -(const Vec& v) { return Vec(x - v.x, y - v.y); }

    bool operator <(const Vec& v) {
        if (y == v.y) return x < v.x;
        return y < v.y;
    }

    bool operator ==(const Vec& v) { return x == v.x && y == v.y; }
} vec_t;

ll ccw(Vec& o, Vec& a, Vec& b) { return (a - o).cross(b - o); }

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, px, py; cin >> n >> px >> py;
    n++;
    vec_t p = Vec(px, py);
    vector<vec_t> pnts(n);
    pnts[0] = p;
    for (int i = 1; i < n; i++) cin >> pnts[i].x >> pnts[i].y;

    int cnt = 0;
    for (; ; cnt++) {
        int s = 0;
        for (int i = 1; i < n; i++) {
            if (pnts[i] < pnts[s]) s = i;
        }
        if (s) pnts[0].swap(pnts[s]);

        for (int i = 1; i < n; i++) pnts[i].sub(pnts[0]);
        p.sub(pnts[0]);
        pnts[0] = Vec();
        sort(pnts.begin() + 1, pnts.end(), [](Vec& a, Vec& b) {
            ll c = a.cross(b);
            if (c == 0) {
                if (a.y == b.y) return abs(a.x) < abs(b.x);
                return a.y < b.y;
            }
            return c > 0;
        });

        stack<int> stk;
        int top = 0;
        bool pused = pnts[0] == p;
        for (int i = 1; i < n; i++) {
            while (!stk.empty() && ccw(pnts[stk.top()], pnts[top], pnts[i]) < 0) {
                if (pnts[top] == p) pused = false;
                top = stk.top();
                stk.pop();
            }
            stk.push(top);
            top = i;
            if (pnts[top] == p) pused = true;
        }
        stk.push(top);

        if (pused) break;

        vector<bool> del(n, false);
        while (!stk.empty()) {
            del[stk.top()] = true;
            stk.pop();
        }
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (del[i]) continue;
            pnts[idx++] = pnts[i];
        }
        n = idx;
        pnts.resize(n);
    }

    cout << cnt << '\n';
}