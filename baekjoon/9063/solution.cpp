#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int minx = inf, miny = inf, maxx = -inf, maxy = -inf;
    while (n--) {
        int x, y; cin >> x >> y;
        if (minx > x) minx = x;
        if (miny > y) miny = y;
        if (maxx < x) maxx = x;
        if (maxy < y) maxy = y;
    }
    cout << (maxx - minx) * (maxy - miny) << '\n';
}