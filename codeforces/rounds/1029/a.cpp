#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        int f = -1, l = -1;
        for (int i = 0; i < n; i++) {
            if (a[i]) {
                if (f < 0) f = i;
                l = i;
            }
        }
        cout << (l - f + 1 <= x ? "YES\n" : "NO\n");
    }
}