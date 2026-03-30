#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> c(n);
        for (int &c: c) cin >> c;
        sort(c.begin(), c.end());

        vector<int> cnt;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur++;
            if (i == n - 1 || c[i] != c[i + 1]) {
                cnt.push_back(cur);
                cur = 0;
            }
        }

        auto gets = [&]() {
            for (int i = *min_element(cnt.begin(), cnt.end()) + 1; i; i--) {
                bool ok = true;
                for (int c: cnt) {
                    int q = c / (i - 1), r = c % (i - 1);
                    if (q < r) {
                        ok = false;
                        break;
                    }
                }
                if (ok) return i;
            }
            return 2;
        };

        int s = gets(), ans = 0;
        for (int c: cnt) ans += (c + s - 1) / s;
        cout << ans << '\n';
    }
}