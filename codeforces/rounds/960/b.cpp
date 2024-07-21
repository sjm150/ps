#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, x, y; cin >> n >> x >> y;
        x--, y--;
        vector<int> a(n);
        for (int i = y; i <= x; i++) a[i] = 1;
        for (int i = x + 1; i < n; i++) a[i] = -a[i - 1];
        for (int i = y - 1; i >= 0; i--) a[i] = -a[i + 1];
        for (int a: a) cout << a << ' ';
        cout << '\n';
    }
}