#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int w, h, a, b;
        cin >> w >> h >> a >> b;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        auto solve = [&]() {
            int dx = abs(x1 - x2), dy = abs(y1 - y2);
            if (dx < a && dy % b != 0) return false;
            if (dy < b && dx % a != 0) return false;
            return dx % a == 0 || dy % b == 0;
        };
        cout << (solve() ? "YES\n" : "NO\n");
    }
}