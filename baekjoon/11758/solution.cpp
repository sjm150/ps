#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int cross(int x1, int y1, int x2, int y2) {
    return x1 * y2 - x2 * y1;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    pair<int, int> p[3];
    for (int i = 0; i < 3; i++) cin >> p[i].X >> p[i].Y;
    int prd = cross(p[1].X - p[0].X, p[1].Y - p[0].Y, p[2].X - p[1].X, p[2].Y - p[1].Y);
    if (prd > 0) cout << 1 << '\n';
    else if (prd < 0) cout << -1 << '\n';
    else cout << 0 << '\n';
}