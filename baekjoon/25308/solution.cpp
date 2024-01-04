#include <bits/stdc++.h>
using namespace std;
const int n = 8;
const double r = sqrt(2);

typedef struct Vec {
    double x, y;
    Vec(): x(0), y(0) {}
    Vec(double x, double y): x(x), y(y) {}

    Vec operator-(Vec& o) { return Vec(x - o.x, y - o.y); }

    Vec operator*(int l) { return Vec(l * x, l * y); }

    double cross(const Vec& o) { return x * o.y - o.x * y; }
} vec_t;

double ccw(vec_t &o, vec_t &a, vec_t &b) {
    return (a - o).cross(b - o);
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vec_t> v;
    v.emplace_back(r, 0);
    v.emplace_back(1, 1);
    v.emplace_back(0, r);
    v.emplace_back(-1, 1);
    v.emplace_back(-r, 0);
    v.emplace_back(-1, -1);
    v.emplace_back(0, -r);
    v.emplace_back(1, -1);

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    int cnt = 0;
    do {
        vector<vec_t> prd;
        for (int i = 0; i < n; i++) prd.push_back(v[i] * a[p[i]]);

        bool poss = true;
        for (int i = 0; i < n; i++) {
            if (ccw(prd[i], prd[(i + 1) % n], prd[(i + 2) % n]) < 0) {
                poss = false;
                break;
            }
        }
        if (poss) cnt++;
    } while (next_permutation(p.begin(), p.end()));

    cout << cnt << '\n';
}