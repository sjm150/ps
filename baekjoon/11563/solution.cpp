#include <bits/stdc++.h>
using namespace std;

typedef struct Point {
    double x; double y;
} point_t;

typedef struct Vector {
    double x; double y;
} vector_t;

typedef struct Line {
    point_t s; point_t e;
} line_t;

Line yls[2000], kls[2000];

vector_t get_vec(point_t& from, point_t& to) {
    return Vector {x: to.x - from.x, y: to.y - from.y};
}

double dot(vector_t& v1, vector_t& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

double cross(vector_t& v1, vector_t& v2) {
    return v1.x * v2.y - v1.y * v2.x;
}

double dst_btw(point_t& p1, point_t& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double get_dst(point_t& p, line_t& l) {
    auto v1 = get_vec(p, l.s);
    auto v2 = get_vec(p, l.e);
    return abs(cross(v1, v2)) / dst_btw(l.s, l.e);
}

bool is_acute(point_t& p1, point_t& p2, point_t& p3) {
    auto v21 = get_vec(p2, p1);
    auto v23 = get_vec(p2, p3);
    auto v31 = get_vec(p3, p1);
    auto v32 = get_vec(p3, p2);
    return dot(v21, v23) > 0 && dot(v31, v32) > 0;
}

double min_dst(line_t& y, line_t& k) {
    double dst = min(min(dst_btw(y.s, k.s), dst_btw(y.s, k.e)), min(dst_btw(y.e, k.s), dst_btw(y.e, k.e)));
    if (is_acute(y.s, k.s, k.e)) dst = min(dst, get_dst(y.s, k));
    if (is_acute(y.e, k.s, k.e)) dst = min(dst, get_dst(y.e, k));
    if (is_acute(k.s, y.s, y.e)) dst = min(dst, get_dst(k.s, y));
    if (is_acute(k.e, y.s, y.e)) dst = min(dst, get_dst(k.e, y));
    return dst;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        double xs, ys, xe, ye;
        cin >> xs >> ys >> xe >> ye;
        yls[i] = Line {s: Point {xs, ys}, e: Point {xe, ye}};
    }
    for (int i = 0; i < m; i++) {
        double xs, ys, xe, ye;
        cin >> xs >> ys >> xe >> ye;
        kls[i] = Line {s: Point {xs, ys}, e: Point {xe, ye}};
    }
    double dst = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dst = min(dst, min_dst(yls[i], kls[j]));
        }
    }
    cout << fixed << setprecision(16);
    cout << dst << '\n';
}