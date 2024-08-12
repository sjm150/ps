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
        auto sqr = [&](ll x) { return x * x; };
        bool poss = true;
        for (auto [x, y]: xy) {
            if (sqr(xt - x) + sqr(yt - y) <= sqr(dx) + sqr(dy)) {
                poss = false;
                break;
            }
        }
        cout << (poss ? "YES\n" : "NO\n");
    }
}