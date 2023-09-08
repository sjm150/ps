#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cross(int x1, int y1, int x2, int y2) {
    return ll(x1) * y2 - ll(x2) * y1;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int x0, y0; cin >> x0 >> y0;
    int px = x0, py = y0;
    long long sur = 0;
    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        sur += cross(x - x0, y - y0, px - x0, py - y0);
        px = x, py = y;
    }
    cout << fixed << setprecision(1);
    cout << double(abs(sur)) / 2 << '\n';
}