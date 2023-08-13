#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

pi bl[200000];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int l, r, a, b; cin >> l >> r >> a >> b;
            bl[i] = {b, l};
        }
        sort(bl, bl + n, greater<pi>());
        map<int, int> port;
        for (int i = 0; i < n; i++) {
            auto& [b, l] = bl[i];
            auto it = port.upper_bound(b);
            if (it != port.begin()) port[l] = prev(it)->second;
            else port[l] = b;
        }
        int q; cin >> q;
        while (q--) {
            int x; cin >> x;
            auto it = port.upper_bound(x);
            if (it != port.begin()) cout << max(prev(it)->second, x) << ' ';
            else cout << x << ' ';
        }
        cout << '\n';
    }
}