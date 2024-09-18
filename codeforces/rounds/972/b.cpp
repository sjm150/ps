#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m, q; cin >> n >> m >> q;
        vector<int> bb(m), b;
        for (int &b: bb) cin >> b;
        sort(bb.begin(), bb.end());
        b.push_back(bb[0]);
        for (int i = 1; i < m; i++) {
            if (bb[i] != bb[i - 1]) b.push_back(bb[i]);
        }
        while (q--) {
            int a; cin >> a;
            auto it = upper_bound(b.begin(), b.end(), a);
            if (it == b.end()) {
                cout << n - b.back() << '\n';
            } else if (it == b.begin()) {
                cout << b[0] - 1 << '\n';
            } else {
                cout << (*it - *prev(it)) / 2 << '\n';
            }
        }
    }
}