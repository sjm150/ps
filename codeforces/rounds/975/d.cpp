#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        vector<int> l(n + 1, n), r(n + 1, -1);
        for (int i = 0; i < n; i++) {
            if (l[a[i]] == n) l[a[i]] = i;
            r[a[i]] = i;
        }
        for (int i = 2; i <= n; i++) {
            l[i] = min(l[i - 1], l[i]);
            r[i] = max(r[i - 1], r[i]);
        }
        auto chk = [&](int x, int t) {
            if (x < l[t]) return r[t] - x + 1 <= t;
            else if (x > r[t]) return x - l[t] + 1 <= t;
            else return r[t] - l[t] + 1 <= t;
        };
        int s = 0, e = n - 1;
        for (int i = 1; i <= n; i++) {
            while (s <= e && !chk(s, i)) s++;
            while (s <= e && !chk(e, i)) e--;
        }
        cout << e - s + 1 << '\n';
    }
}