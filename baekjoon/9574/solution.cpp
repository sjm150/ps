#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, x, y, z; cin >> n >> x >> y >> z;
    map<int, int> d;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        d[a] += y - x;
        d[b + 1] += z - y;
    }
    int cur = n * x, ans = cur;
    for (auto [t, d]: d) {
        cur += d;
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}