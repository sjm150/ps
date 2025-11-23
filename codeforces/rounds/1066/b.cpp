#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        string s;
        cin >> s;
        x = abs(x), y = abs(y);
        for (char a: s) {
            if (a == '4') {
                if (x < y) {
                    if (y) y--;
                } else {
                    if (x) x--;
                }
            } else {
                if (x) x--;
                if (y) y--;
            }
        }
        cout << (x == 0 && y == 0 ? "YES\n" : "NO\n");
    }
}