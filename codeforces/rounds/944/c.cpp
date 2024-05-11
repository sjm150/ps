#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        auto bet = [&](int x) {
            return a < x && x < b;
        };
        if ((bet(c) && !bet(d)) || (!bet(c) && bet(d))) cout << "YES\n";
        else cout << "NO\n";
    }
}