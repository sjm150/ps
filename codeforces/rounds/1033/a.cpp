#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int l1, b1, l2, b2, l3, b3;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
        bool ok = false;
        if (l1 == l3 && l1 == b1 + b2 + b3) ok = true;
        if (b1 == b3 && b1 == l1 + l2 + l3) ok = true;
        if (l1 == l2 + l3 && b2 == b3 && l1 == b1 + b2) ok = true;
        if (b1 == b2 + b3 && l2 == l3 && b1 == l1 + l2) ok = true;
        cout << (ok ? "YES\n" : "NO\n");
    }
}