#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;

typedef struct Vec {
    int x, y;
    Vec(): x(0), y(0) {}
    Vec(int x, int y): x(x), y(y) {}

    void swap(Vec& o) {
        int tx = x, ty = y;
        x = o.x, y = o.y;
        o.x = tx, o.y = ty;
    }

    void sub(Vec& o) { x -= o.x, y -= o.y; }

    int cross(const Vec& o) { return x * o.y - o.x * y; }

    Vec operator-(Vec& o) { return Vec(x - o.x, y - o.y); }

    bool operator<(Vec& o) {
        if (y == o.y) return x < o.x;
        return y < o.y;
    }
} vec_t;

int ccw(vec_t& o, vec_t& a, vec_t& b) {
    return (a - o).cross(b - o);
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (int t = 1; ; t++) {
        int n; cin >> n;
        if (n == 0) break;
        vector<vec_t> p(n);
        int o = 0;
        for (int i = 0; i < n; i++) {
            cin >> p[i].x >> p[i].y;
            if (p[i] < p[o]) o = i;
        }
        swap(p[0], p[o]);

        for (int i = 1; i < n; i++) p[i].sub(p[0]);
        p[0] = Vec();
        sort(p.begin() + 1, p.end(), [](vec_t& a, vec_t& b) {
            int c = a.cross(b);
            if (c == 0) {
                if (a.y == b.y) return abs(a.x) < abs(b.x);
                return a.y < b.y;
            }
            return c > 0;
        });

        vector<int> cvx;
        int top = 0;
        for (int i = 1; i < n; i++) {
            while (!cvx.empty() && ccw(p[cvx.back()], p[top], p[i]) <= 0) {
                top = cvx.back();
                cvx.pop_back();
            }
            cvx.push_back(top);
            top = i;
        }
        cvx.push_back(top);

        vec_t b = p[cvx[0]] - p[cvx.back()];
        double len = sqrt(b.x * b.x + b.y * b.y);
        double d = 0;
        for (int i = 0; i < cvx.size(); i++) d = max(d, abs(b.cross(p[cvx[i]] - p[cvx[0]])) / len);

        double mind = d;
        for (int i = 1; i < cvx.size(); i++) {
            vec_t b = p[cvx[i]] - p[cvx[i - 1]];
            double len = sqrt(b.x * b.x + b.y * b.y);
            double d = 0;
            for (int j = 0; j < cvx.size(); j++) d = max(d, abs(b.cross(p[cvx[j]] - p[cvx[i]])) / len);
            mind = min(mind, d);
        }

        cout << "Case " << t << ": " << setprecision(2) << fixed << ceil(mind * 100 - eps) / 100 << '\n';
    }
}