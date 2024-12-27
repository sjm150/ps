#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int ans = 0;
    while (n--) {
        int a[3];
        for (int &a: a) cin >> a;
        sort(a, a + 3);
        if (a[0] == a[2]) ans = max(ans, 10000 + 1000 * a[0]);
        else if (a[0] == a[1] || a[1] == a[2]) ans = max(ans, 1000 + 100 * a[1]);
        else ans = max(ans, 100 * a[2]);
    }
    cout << ans << '\n';
}