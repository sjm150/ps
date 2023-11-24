#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 1e9;

typedef struct Vec {
    int x, y;
    Vec(): x(0), y(0) {}
    Vec(int x, int y): x(x), y(y) {}

    void sub(const Vec& v) {
        x -= v.x;
        y -= v.y;
    }

    Vec operator -(const Vec& v) { return Vec(x - v.x, y - v.y); }

    void swap(Vec& v) {
        x ^= v.x;
        v.x ^= x;
        x ^= v.x;
        y ^= v.y;
        v.y ^= y;
        y ^= v.y;
    }

    ll cross(const Vec& v) { return ll(x) * v.y - ll(y) * v.x; }
} vec_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<vec_t> pnts(n);
    int mini = 0;
    for (int i = 0; i < n; i++) {
        cin >> pnts[i].x >> pnts[i].y;
        if (pnts[i].y < pnts[mini].y) mini = i;
        else if (pnts[i].y == pnts[mini].y && pnts[i].x < pnts[mini].x) mini = i;
    }
    if (mini) pnts[0].swap(pnts[mini]);

    for (int i = 1; i < n; i++) pnts[i].sub(pnts[0]);
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
    for (int i = 1; i < n; i++) {
        while (!stk.empty() && (pnts[top] - pnts[stk.top()]).cross(pnts[i] - pnts[stk.top()]) <= 0) {
            top = stk.top();
            stk.pop();
        }
        stk.push(top);
        top = i;
    }

    cout << stk.size() + 1 << '\n';
}