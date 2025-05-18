#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        bool ok = false;
        for (int i = 0; i < n - 1; i++) {
            if (!a[i] && !a[i + 1]) {
                ok = true;
                break;
            }
        }
        bool all = true;
        for (int a: a) {
            if (!a) {
                all = false;
                break;
            }
        }
        cout << (ok || all ? "YES\n" : "NO\n");
    }
}