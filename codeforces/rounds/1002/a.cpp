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
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int ak = 1, bk = 1;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] != a[i + 1]) ak++;
            if (b[i] != b[i + 1]) bk++;
        }
        cout << (ak > 2 || bk > 2 || (ak >= 2 && bk >= 2) ? "YES\n" : "NO\n");
    }
}