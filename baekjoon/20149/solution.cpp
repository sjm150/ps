#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct Vec {
    int x, y;
    Vec(): x(0), y(0) {}
    Vec(int x, int y): x(x), y(y) {}

    bool operator<(const Vec& o) const {
        if (x == o.x) return y < o.y;
        return x < o.x;
    }

    bool operator==(const Vec& o) const { return x == o.x && y == o.y; }

    Vec operator-(Vec& o) { return Vec(x - o.x, y - o.y); }

    ll cross(const Vec& o) { return ll(x) * o.y - ll(o.x) * y; }

} vec_t;

ostream& operator<<(ostream& o, const Vec& v) {
    o << v.x << ' ' << v.y;
    return o;
}

int ccw(Vec& o, Vec& a, Vec& b) {
    ll c = (a - o).cross(b - o);
    if (c < 0) return -1;
    else if (c > 0) return 1;
    else return 0;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vec_t p[4];
    for (int i = 0; i < 4; i++) cin >> p[i].x >> p[i].y;
    int r1 = ccw(p[0], p[1], p[2]) * ccw(p[0], p[1], p[3]);
    int r2 = ccw(p[2], p[3], p[0]) * ccw(p[2], p[3], p[1]);
    if (r1 == 0 && r2 == 0) {
        if (max(p[0], p[1]) < min(p[2], p[3]) || max(p[2], p[3]) < min(p[0], p[1])) cout << 0 << '\n';
        else {
            cout << 1 << '\n';
            if ((p[1] - p[0]).cross(p[3] - p[2])) {
                double t = (double)((p[0] - p[2]).cross(p[2] - p[3])) / (p[0] - p[1]).cross(p[2] - p[3]);
                cout << fixed << setprecision(10) << p[0].x + t * (p[1].x - p[0].x) << ' ' << p[0].y + t * (p[1].y - p[0].y) << '\n';        
            } else if (max(p[0], p[1]) == min(p[2], p[3])) {
                cout << max(p[0], p[1]) << '\n';
            } else if (max(p[2], p[3]) == min(p[0], p[1])) {
                cout << max(p[2], p[3]) << '\n';
            }
        }
    } else if (r1 <= 0 && r2 <= 0) {
        cout << 1 << '\n';
        double t = (double)((p[0] - p[2]).cross(p[2] - p[3])) / (p[0] - p[1]).cross(p[2] - p[3]);
        cout << fixed << setprecision(10) << p[0].x + t * (p[1].x - p[0].x) << ' ' << p[0].y + t * (p[1].y - p[0].y) << '\n';
    } else {
        cout << 0 << '\n';
    }
}