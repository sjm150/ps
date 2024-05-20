#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int x, y; cin >> x >> y;
        int cnt = (y + 1) / 2;
        x -= cnt * 15 - y * 4;
        cnt += (max(0, x) + 14) / 15;
        cout << cnt << '\n';
    }
}