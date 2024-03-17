#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; i++) cin >> a[i];

        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; i++) cnt[a[i]]++;

        vector<int> l, r, lr;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 0) r.push_back(i);
            else if (cnt[i] == 1) lr.push_back(i);
            else l.push_back(i);
        }

        int lcnt = 2 * k;
        for (int i = 0; lcnt > 1 && i < l.size(); i++, lcnt -= 2) cout << l[i] << ' ' << l[i] << ' ';
        for (int i = 0; lcnt && i < lr.size(); i++, lcnt--) cout << lr[i] << ' ';
        cout << '\n';
        int rcnt = 2 * k;
        for (int i = 0; rcnt > 1 && i < r.size(); i++, rcnt -= 2) cout << r[i] << ' ' << r[i] << ' ';
        for (int i = 0; rcnt && i < lr.size(); i++, rcnt--) cout << lr[i] << ' ';
        cout << '\n';
    }
}