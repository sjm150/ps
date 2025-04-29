#include <bits/stdc++.h>
using namespace std;

typedef struct Vec {
    int x, y;
    Vec(): x(0), y(0) {}
    Vec(int x, int y): x(x), y(y) {}

    void sub(const Vec& v) {
        x -= v.x;
        y -= v.y;
    }
    int cross(const Vec& v) { return x * v.y - v.x * y; }

    Vec operator -(const Vec& v) { return Vec(x - v.x, y - v.y); }
    bool operator <(const Vec& v) {
        if (y == v.y) return x < v.x;
        return y < v.y;
    }
    bool operator ==(const Vec& v) { return x == v.x && y == v.y; }
} vec_t;

int ccw(vec_t &o, vec_t &a, vec_t &b) { return (a - o).cross(b - o); }

double dst(vec_t &a, vec_t &b) {
    auto sqr = [](int x) { return x * x; };
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, r;
    cin >> n >> r;
    vector<vec_t> xy(n);
    for (auto &[x, y]: xy) cin >> x >> y;

    swap(xy[0], xy[min_element(xy.begin(), xy.end()) - xy.begin()]);
    auto o = xy[0];
    for (auto &cur: xy) cur.sub(o);
    sort(xy.begin() + 1, xy.end(), [](vec_t &a, vec_t & b) {
        int c = a.cross(b);
        if (c == 0) return a < b;
        return c > 0;
    });

    vector<int> stk;
    int top = 0;
    for (int i = 1; i < n; i++) {
        while (!stk.empty() && ccw(xy[stk.back()], xy[top], xy[i]) <= 0) {
            top = stk.back();
            stk.pop_back();
        }
        stk.push_back(top);
        top = i;
    }
    stk.push_back(top);

    double ans = M_PI * 2 * r + dst(xy[stk[0]], xy[stk.back()]);
    for (int i = 1; i < stk.size(); i++) ans += dst(xy[stk[i - 1]], xy[stk[i]]);
    cout << fixed << setprecision(9) << ans << '\n';
}