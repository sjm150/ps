#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;
        vector<pair<int, int>> cmin, cmex;
        while (q--) {
            int c, l, r;
            cin >> c >> l >> r;
            (c == 1 ? cmin : cmex).emplace_back(l - 1, r - 1);
        }
        sort(cmin.begin(), cmin.end());
        sort(cmex.begin(), cmex.end());

        vector<int> c(n, 0);
        int idx = 0, sz = cmin.size(), mxr = -1;
        for (int i = 0; i < n; i++) {
            while (idx < sz && cmin[idx].first <= i) mxr = max(mxr, cmin[idx++].second);
            if (i <= mxr) c[i] = 1;
        }
        idx = 0, sz = cmex.size(), mxr = -1;
        for (int i = 0; i < n; i++) {
            while (idx < sz && cmex[idx].first <= i) mxr = max(mxr, cmex[idx++].second);
            if (i <= mxr) {
                if (c[i]) c[i] = 3;
                else c[i] = 2;
            }
        }

        vector<int> a(n);
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (c[i] == 1) {
                a[i] = k;
            } else if (c[i] == 2) {
                a[i] = cur;
                cur = (cur + 1) % k;
            } else {
                a[i] = k + 1;
            }
        }

        for (int a: a) cout << a << ' ';
        cout << '\n';
    }
}