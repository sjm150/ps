#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int x, y, r; cin >> x >> y >> r;
    int dx[] = {-1, 1, 1, -1};
    int dy[] = {1, 1, -1, -1};
    for (int i = 0; i < 4; i++) cout << x + dx[i] * r << ' ' << y + dy[i] * r << '\n';
}