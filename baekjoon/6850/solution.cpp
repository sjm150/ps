#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
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

        int cross(const Vec& v) { return x * v.y - v.x * y; }

        Vec operator -(const Vec& v) { return Vec(x - v.x, y - v.y); }

        bool operator <(const Vec& v) {
            if (y == v.y) return x < v.x;
            return y < v.y;
        }

        bool operator ==(const Vec& v) { return x == v.x && y == v.y; }
    } vec_t;
    auto ccw = [](Vec& o, Vec& a, Vec& b) { return (a - o).cross(b - o); };

    int n;
    cin >> n;
    vector<vec_t> p(n);
    for (auto &[x, y]: p) cin >> x >> y;

    int o = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] < p[o]) o = i;
    }
    swap(p[o], p[0]);

    for (int i = 1; i < n; i++) p[i].sub(p[0]);
    p[0] = Vec();
    sort(p.begin() + 1, p.end(), [](vec_t &a, vec_t &b) {
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

    int ans = 0;
    for (int i = 1; i < cvx.size() - 1; i++) ans += p[cvx[i]].cross(p[cvx[i + 1]]);
    cout << ans / 100 << '\n';
}