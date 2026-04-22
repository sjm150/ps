#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (;;) {
        int x, y, s;
        cin >> x >> y >> s;
        if (x == 0) break;
        int ans = 0;
        for (int i = 1; i <= s - i; i++) {
            int j = s - i;
            int oi = i * 100 / (100 + x), oj = j * 100 / (100 + x);
            while (oi * (100 + x) / 100 < i) oi++;
            if (oi * (100 + x) / 100 != i) continue;
            while (oj * (100 + x) / 100 < j) oj++;
            if (oj * (100 + x) / 100 != j) continue;
            ans = max(ans, oi * (100 + y) / 100 + oj * (100 + y) / 100);
        }
        cout << ans << '\n';
    }
}