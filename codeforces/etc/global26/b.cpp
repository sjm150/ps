#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        long long x; cin >> x;
        bool poss = true;
        while (x >= 10) {
            int r = x % 10;
            if (r == 9) {
                poss = false;
                break;
            }
            x = x / 10 - 1;
        }
        if (x) poss = false;
        cout << (poss ? "YES\n" : "NO\n");
    }
}