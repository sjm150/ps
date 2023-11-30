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

    void swap(Vec& v) {
        int tx = x, ty = y;
        x = v.x, y = v.y;
        v.x = tx, v.y = ty;
    }

    int cross(const Vec& v) { return x * v.y - v.x * y; }

    double dst(const Vec& v) {
        return sqrt((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y));
    }

    Vec operator -(const Vec& v) { return Vec(x - v.x, y - v.y); }

    bool operator <(Vec& v) {
        if (y == v.y) return x < v.x;
        return y < v.y;
    }
} vec_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, l; cin >> n >> l;
    vector<vec_t> pnts(n);
    int mini = 0;
    for (int i = 0; i < n; i++) {
        cin >> pnts[i].x >> pnts[i].y;
        if (pnts[i] < pnts[mini]) mini = i;
    }
    if (mini) pnts[0].swap(pnts[mini]);

    for (int i = 1; i < n; i++) pnts[i].sub(pnts[0]);
    pnts[0] = Vec();
    sort(pnts.begin() + 1, pnts.end(), [](Vec& a, Vec& b) {
        int c = a.cross(b);
        if (c == 0) {
            if (a.y == b.y) return abs(a.x) < abs(b.x);
            return a.y < b.y;
        }
        return c > 0;
    });

    stack<int> stk;
    int top = 0;
    for (int i = 1; i < n; i++) {
        while (!stk.empty() && (pnts[top] - pnts[stk.top()]).cross(pnts[i] - pnts[stk.top()]) <= 0) {
            top = stk.top();
            stk.pop();
        }
        stk.push(top);
        top = i;
    }

    double len = 2 * l * M_PI + pnts[0].dst(pnts[top]);
    while (!stk.empty()) {
        len += pnts[top].dst(pnts[stk.top()]);
        top = stk.top();
        stk.pop();
    }
    cout << int(round(len)) << '\n';
}