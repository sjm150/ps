#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int a, x, y;
        cin >> a >> x >> y;
        if (x > y) swap(x, y);
        cout << (x <= a && a <= y ? "NO\n" : "YES\n");
    }
}