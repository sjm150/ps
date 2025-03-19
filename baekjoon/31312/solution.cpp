#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, a, b; cin >> n >> a >> b;
    bool mn = false, mx = false;
    for (int i = 0; i < n - 1; i++) {
        int w; cin >> w;
        if (w == a) mn = true;
        if (w == b) mx = true;
    }
    if (mn && mx) {
        for (int i = a; i <= b; i++) cout << i << '\n';
    } else if (mn) {
        cout << b << '\n';
    } else if (mx) {
        cout << a << '\n';
    } else if (a == b) {
        cout << a << '\n';
    } else {
        cout << -1 << '\n';
    }
}