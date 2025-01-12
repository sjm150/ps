#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int &a: a) cin >> a;
        for (int &b: b) cin >> b;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                idx = i;
                break;
            }
        }
        bool ok = true;
        if (idx >= 0) {
            for (int i = 0; i < n; i++) {
                if (idx == i) continue;
                if (a[i] - b[i] < b[idx] - a[idx]) {
                    ok = false;
                    break;
                }
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}