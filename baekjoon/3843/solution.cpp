#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const double eps = 1e-6;
    string s;
    for (;;) {
        cin >> s;
        if (s[0] == 'E') break;
        double ax, ay, bx, by, cx, cy;
        ax = stod(s);
        cin >> ay >> bx >> by >> cx >> cy;
        
        double vx = ay - by, vy = bx - ax;
        double mx = (ax + bx) / 2, my = (ay + by) / 2;
        double ux = by - cy, uy = cx - bx;
        double nx = (bx + cx) / 2, ny = (by + cy) / 2;

        double w = abs(vy) < eps ? (my - ny) / uy : ((ny - my) / vy * vx + mx - nx) / (ux - uy / vy * vx);
        double ox = w * ux + nx, oy = w * uy + ny;
        
        ax -= ox, ay -= oy, bx -= ox, by -= oy, cx -= ox, cy -= oy;

        for (int i = 3; i <= 1000; i++) {
            double a = acos(-1) * 2 / i, x = ax, y = ay;
            bool b = false, c = false;
            for (int j = 0; j < i; j++) {
                if (abs(x - bx) < 1e-1 && abs(y - by) < 1e-1) b = true;
                if (abs(x - cx) < 1e-1 && abs(y - cy) < 1e-1) c = true;
                double nx = x * cos(a) - y * sin(a), ny = x * sin(a) + y * cos(a);
                swap(x, nx);
                swap(y, ny);
            }
            if (b && c) {
                cout << i << '\n';
                break;
            }
        }
    }
}