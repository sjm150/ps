#include <iostream>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m, k, h;
        cin >> n >> m >> k >> h;
        int cnt = 0;
        while (n--) {
            int cur; cin >> cur;
            if (cur == h) continue;
            int diff = abs(h - cur);
            int d = diff / k;
            int r = diff % k;
            if (r == 0 && d < m) cnt++;
        }
        cout << cnt << '\n';
    }
}