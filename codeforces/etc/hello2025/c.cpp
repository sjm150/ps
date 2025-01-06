#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int l, r; cin >> l >> r;
        int m = 0;
        vector<int> d;
        for (int b = 1 << 29; b; b >>= 1) {
            if ((l & b) == (r & b)) {
                if (!d.empty()) {
                    if ((r & b) == 0) m |= b;
                } else {
                    m |= (r & b);
                }
            } else {
                d.push_back(b);
            }
        }
        for (int b: d) {
            if (m <= l && (m | b) < r) m |= b;
        }
        cout << l << ' ' << m << ' ' << r << '\n';
    }
}