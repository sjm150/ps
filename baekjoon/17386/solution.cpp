#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct Vec {
    ll x, y;
    Vec(): x(0), y(0) {}
    Vec(int x, int y): x(x), y(y) {}
    Vec operator-(Vec& o) { return Vec(x - o.x, y - o.y); }
    ll cross(const Vec& o) { return x * o.y - o.x * y; }
} vec_t;

int ccw(vec_t& o, vec_t& a, vec_t& b) {
    ll c = (a - o).cross(b - o);
    if (c > 0) return 1;
    else if (c < 0) return -1;
    return 0;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vec_t v[4];
    for (int i = 0; i < 4; i++) cin >> v[i].x >> v[i].y;
    int c1 = ccw(v[0], v[1], v[2]) * ccw(v[0], v[1], v[3]);
    int c2 = ccw(v[2], v[3], v[0]) * ccw(v[2], v[3], v[1]);
    if (c1 <= 0 && c2 <= 0) cout << 1 << '\n';
    else cout << 0 << '\n';
}