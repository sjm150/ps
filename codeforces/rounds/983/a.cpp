#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int cnt = 0;
        for (int i = 0; i < 2 * n; i++) {
            int s; cin >> s;
            cnt += s;
        }
        cout << cnt % 2 << ' ' << (cnt > n ? 2 * n - cnt : cnt) << '\n';
    }
}