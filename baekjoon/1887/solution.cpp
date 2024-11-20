#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t, n; cin >> t >> n;
    vector<int> c(n, 0);
    for (int &c: c) {
        int z; cin >> z;
        while (z--) {
            int k; cin >> k;
            c |= 1 << (k - 1);
        }
    }
    int ans = 0, sz = 1 << t;
    for (int i = 0; i < sz; i++) {
        bool ok = true;
        for (int c: c) {
            if ((i & c) == c) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }
    cout << ans << '\n';
}