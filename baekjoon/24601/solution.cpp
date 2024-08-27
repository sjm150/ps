#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef struct Point {
    int x, y;
    Point() {}
} p_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<p_t> xy(n);
    for (auto &[x, y]: xy) cin >> x >> y;
    auto area = [&](p_t &a, p_t &b) {
        return abs(ll(a.x - xy[0].x) * (b.y - xy[0].y) - ll(a.y - xy[0].y) * (b.x - xy[0].x));
    };
    vector<ll> a(n - 1, 0);
    for (int i = 1; i < n - 1; i++) a[i] = a[i - 1] + area(xy[i], xy[i + 1]);
    int idx = 1;
    while (idx < n - 1 && a[idx] * 2 < a.back()) idx++;
    ll t = a.back() - 2 * a[idx - 1];
    ll u = 2 * (a[idx] - a[idx - 1]) - t;
    auto pnt = [&](int a, int b) {
        return (double(u) * a + double(t) * b) / (u + t);
    };
    cout << fixed << setprecision(7) << pnt(xy[idx].x, xy[idx + 1].x) << ' ' << pnt(xy[idx].y, xy[idx + 1].y) << '\n';
}