#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int cur = 0, ans = 0;
    for (int i = 0; i < 4; i++) {
        int a, b; cin >> a >> b;
        cur += b - a;
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}