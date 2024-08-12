#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<int, int>> xy(n);
        for (auto &[x, y]: xy) cin >> x >> y;
        int xs, ys, xt, yt; cin >> xs >> ys >> xt >> yt;
        int dx = xt - xs, dy = yt - ys;

        auto cross = [&](ll x1, ll y1, ll x2, ll y2) {
            return x1 * y2 - x2 * y1;
        };
        auto ccw = [&](ll x1, ll y1, ll x2, ll y2) {
            ll c = cross(x1, y1, x2, y2);
            if (c > 0) return 1;
            else if (c < 0) return -1;
            else return 0;
        };
        auto sqr = [&](ll x) { return x * x; };

        bool poss = true;
        for (auto [x, y]: xy) {
            if (sqr(xt - x) + sqr(yt - y) <= sqr(dx) + sqr(dy)) {
                poss = false;
                break;
            }
            if (ccw(-dy, dx, xs - x, ys - y) * ccw(-dy, dx, xt - x, yt - y) < 0 &&
                abs(dy * ll(x - xs) - dx * ll(y - ys)) <= abs(dx * ll(xs - x) + dy * ll(ys - y))) {
                poss = false;
                break;
            }
        }

        cout << (poss ? "YES\n" : "NO\n");
    }
}