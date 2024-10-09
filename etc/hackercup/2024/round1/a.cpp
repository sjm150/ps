#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int T; cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        int n; cin >> n;
        double mn = 0, mx = 1e9;
        for (int i = 1; i <= n; i++) {
            int a, b; cin >> a >> b;
            mn = max(mn, double(i) / b);
            if (a) mx = min(mx, double(i) / a);
        }
        cout << "Case #" << testcase << ": ";
        if (mn <= mx) cout << fixed << setprecision(7) << mn << '\n';
        else cout << -1 << '\n';
    }
}