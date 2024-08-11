#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int c, n; cin >> c >> n;
    vector<int> mn(c + 1, 1e9);
    mn[0] = 0;
    while (n--) {
        int x, y; cin >> x >> y;
        for (int i = 0; i < c; i++) mn[min(i + y, c)] = min(mn[min(i + y, c)], mn[i] + x);
    }
    cout << mn[c] << '\n';
}