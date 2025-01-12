#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k, l; cin >> n >> k >> l;
        k *= 2, l *= 2;
        vector<int> a(n);
        for (int &a: a) {
            cin >> a;
            a *= 2;
        }
        int p = k, s = a[0];
        for (int i = 1; i < n; i++) {
            int mn = a[i] - s, mx = a[i] + s;
            if (p < mn) {
                int d = mn - p;
                s += d / 2;
                p += d / 2 + k;
            } else {
                p = min(mx, p) + k;
            }
        }
        if (p < l) s += l - p;
        cout << s << '\n';
    }
}