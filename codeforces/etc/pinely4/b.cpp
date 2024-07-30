#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> b(n - 1), a(n);
        for (int &b: b) cin >> b;
        a[0] = b[0], a.back() = b.back();
        for (int i = 1; i < n - 1; i++) a[i] = b[i - 1] | b[i];
        bool poss = true;
        for (int i = 0; i < n - 1; i++) {
            if (b[i] != (a[i] & a[i + 1])) {
                poss = false;
                break;
            }
        }
        if (poss) {
            for (int a: a) cout << a << ' ';
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}