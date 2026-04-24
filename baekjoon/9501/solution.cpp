#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        int ans = 0;
        while (n--) {
            int v, f, c;
            cin >> v >> f >> c;
            ans += v * f >= d * c;
        }
        cout << ans << '\n';
    }
}