#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        int idx = -1;
        vector<int> mn(n), mx(n);
        if (abs(a[0]) > 1) {
            idx = 0;
            mn[0] = mx[0] = 0;
        } else {
            mn[0] = mx[0] = a[0];
        }
        for (int i = 1; i < n; i++) {
            if (abs(a[i]) > 1) {
                idx = i;
                mn[i] = mx[i] = 0;
                continue;
            }
            mn[i] = mx[i] = a[i];
            if (mn[i - 1] < 0) mn[i] += mn[i - 1];
            if (mx[i - 1] > 0) mx[i] += mx[i - 1];
        }

        pair<int, int> ans = {min(*min_element(mn.begin(), mn.end()), 0), max(*max_element(mx.begin(), mx.end()), 0)}, ans2 = {0, -1};
        if (idx >= 0) {
            int lmn = 0, lmx = 0, cur = 0;
            for (int i = idx - 1; i >= 0; i--) {
                cur += a[i];
                lmn = min(lmn, cur);
                lmx = max(lmx, cur);
            }
            int rmn = 0, rmx = 0;
            cur = 0;
            for (int i = idx + 1; i < n; i++) {
                cur += a[i];
                rmn = min(rmn, cur);
                rmx = max(rmx, cur);
            }
            int l = lmn + rmn + a[idx], r = lmx + rmx + a[idx];
            if ((l <= ans.first && ans.first <= r) || (l <= ans.second && ans.second <= r)) ans = {min(l, ans.first), max(r, ans.second)};
            else ans2 = {l, r};
        }

        if (ans2.first > ans2.second) {
            cout << ans.second - ans.first + 1 << '\n';
            for (int i = ans.first; i <= ans.second; i++) cout << i << ' ';
            cout << '\n';
        } else {
            cout << ans.second - ans.first + 1 + ans2.second - ans2.first + 1 << '\n';
            if (ans > ans2) swap(ans, ans2);
            for (int i = ans.first; i <= ans.second; i++) cout << i << ' ';
            for (int i = ans2.first; i <= ans2.second; i++) cout << i << ' ';
            cout << '\n';
        }
    }
}