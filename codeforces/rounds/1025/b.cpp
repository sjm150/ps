#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        auto calc = [](int n, int m) {
            int cnt = 0;
            for (; n > 1; n = (n + 1) / 2) cnt++;
            for (; m > 1; m = (m + 1) / 2) cnt++;
            return cnt;
        };
        cout << min(calc(min(a, n - a + 1), m), calc(n, min(b, m - b + 1))) + 1 << '\n';
    }
}