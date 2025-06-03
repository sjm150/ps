#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int fib[12];
    fib[0] = fib[1] = 1;
    for (int i = 2; i < 12; i++) fib[i] = fib[i - 1] + fib[i - 2];
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        while (m--) {
            int w, l, h;
            cin >> w >> l >> h;
            cout << int(max(w, max(l, h)) >= fib[n - 1] + fib[n] && min(w, min(l, h)) >= fib[n]);
        }
        cout << '\n';
    }
}