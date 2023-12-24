#include <bits/stdc++.h>
using namespace std;

typedef struct Vec {
    int x, y, idx = -1;
    Vec(): x(0), y(0) {}
    Vec(int x, int y): x(x), y(y) {}

    void swap(Vec& o) {
        int tx = x, ty = y;
        int ti = idx;
        x = o.x, y = o.y;
        idx = o.idx;
        o.x = tx, o.y = ty;
        o.idx = ti;
    }

    void sub(Vec& o) {
        x -= o.x;
        y -= o.y;
    }

    int cross(const Vec& o) { return x * o.y - o.x * y; }

    bool operator<(Vec& o) {
        if (y == o.y) return x < o.x;
        return y < o.y;
    }

    Vec operator-(Vec& o) { return Vec(x - o.x, y - o.y); }
} vec_t;

int ccw(Vec& o, Vec& a, Vec& b) {
    return (a - o).cross(b - o);
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vec_t> p(n);
        int o = 0;
        for (int i = 0; i < n; i++) {
            p[i].idx = i;
            cin >> p[i].x >> p[i].y;
            if (p[i] < p[o]) o = i;
        }

        p[0].swap(p[o]);
        for (int i = 1; i < n; i++) p[i].sub(p[0]);
        p[0].x = 0, p[0].y = 0;
        sort(p.begin() + 1, p.end(), [](Vec& a, Vec& b){
            int c = a.cross(b);
            if (c == 0) {
                if (a.y == b.y) return abs(a.x) < abs(b.x);
                return a.y < b.y;
            }
            return c > 0;
        });

        int r = n - 1;
        for (; r > 0; r--) {
            if (ccw(p[0], p[r - 1], p[r])) break;
        }
        reverse(p.begin() + r, p.end());
    
        for (auto &p: p) cout << p.idx << ' ';
        cout << '\n';
    }
}