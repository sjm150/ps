#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int a, b;
    cin >> a >> b;
    int d = abs(a - b);
    if (d) {
        while (d % 2 == 0) d /= 2;
    }
    for (int t = 0; t < 5; t++) {
        int p, q;
        cin >> p >> q;
        bool ok;
        if (d) ok = p != q && (a < b) == (p < q) && abs(p - q) % d == 0;
        else ok = p == q;
        cout << (ok ? "Y\n" : "N\n");
    }
}