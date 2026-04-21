#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int mxn = 1e6;
    vector<int> pref = {1};
    for (int i = 1; pref.back() < mxn; i++) pref.push_back(pref.back() + 4 * i + 1);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n, x, y;
        cin >> n >> x >> y;
        x = abs(x);
        int d = (x + y) / 2;

        auto solve = [&]() {
            if (d >= int(pref.size())) return 0.0;
            if (pref[d] <= n) return 1.0;
            if (pref[d - 1] >= n) return 0.0;
            if (x == 0) return 0.0;

            int r = n - pref[d - 1];
            if (r <= y) return 0.0;

            double ret = 0, lp = -r;
            for (int i = 0; i <= r; i++) {
                if (i) lp += log2(r + 1 - i) - log2(i);
                if (i + max(0, r - i - x - y) > y) ret += exp2(lp);
            }

            return ret;
        };

        cout << "Case #" << tc << ": " << setprecision(8) << fixed << solve() << '\n';
    }
}