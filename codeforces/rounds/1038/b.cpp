#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long ans = 0;
        while (n--) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            if (b > d) {
                ans += c;
            } else {
                ans += max(0, c - a) + max(0, d - b);
            }
        }
        cout << ans << '\n';
    }
}