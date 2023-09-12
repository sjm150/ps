#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct Vec {
    int x, y;
} vec_t;

vec_t sub(vec_t& v1, vec_t& v2) {
    return Vec { x: v1.x - v2.x, y : v1.y - v2.y };
}

bool comp(const vec_t& v1, const vec_t& v2) {
    if (v1.x == v2.x) return v1.y < v2.y;
    return v1.x < v2.x;
}

vec_t min(const vec_t& v1, const vec_t& v2) {
    if (comp(v1, v2)) return v1;
    else return v2;
}

vec_t max(const vec_t& v1, const vec_t& v2) {
    if (comp(v2, v1)) return v1;
    else return v2;
}

ll cross(const vec_t& v1, const vec_t& v2) {
    return ll(v1.x) * v2.y - ll(v2.x) * v1.y;
}

int ccw(vec_t& v0, vec_t& v1, vec_t& v2) {
    ll prod = cross(sub(v1, v0), sub(v2, v0));
    if (prod < 0) return -1;
    else if (prod > 0) return 1;
    else return 0;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int x[4], y[4];
    for (int i = 0; i < 4; i++) cin >> x[i] >> y[i];
    vec_t v0 = Vec { x: x[0], y: y[0] };
    vec_t v1 = Vec { x: x[1], y: y[1] };
    vec_t v2 = Vec { x: x[2], y: y[2] };
    vec_t v3 = Vec { x: x[3], y: y[3] };
    int r1 = ccw(v0, v1, v2) * ccw(v0, v1, v3);
    int r2 = ccw(v2, v3, v0) * ccw(v2, v3, v1);
    if (r1 == 0 && r2 == 0) {
        if (comp(max(v0, v1), min(v2, v3)) || comp(max(v2, v3), min(v0, v1))) cout << 0 << '\n';
        else cout << 1 << '\n';
    } else if (r1 <= 0 && r2 <= 0) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
}