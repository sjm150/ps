#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (;;) {
        int n; cin >> n;
        if (!n) break;
        int mx = 1 << n;
        vector<int> h(mx + 1, n), t(mx * 2);
        iota(t.begin() + mx, t.end(), 1);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < (1 << i); j++) {
                int k; cin >> k;
                h[k] = i;
                t[(1 << i) + j] = k;
            }
        }
        int q; cin >> q;
        while (q--) {
            int k; cin >> k;
            set<int> s;
            for (int i = mx + k - 1; i; i /= 2) s.insert(t[i]);
            cout << "Player " << k << " can be ranked as high as " << s.size() << " or as low as " << (1 << n) - (1 << (n - h[k])) + 1 << ".\n";
        }
        cout << '\n';
    }
}