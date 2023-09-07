#include <bits/stdc++.h>
using namespace std;
const int mx = 1e7;

int dvs[mx + 1];
void init() {
    for (int i = 2; i * i <= mx; i++) {
        if (dvs[i]) continue;
        for (int j = i * i; j <= mx; j += i) dvs[j] = i;
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    init();
    int t; cin >> t;
    while (t--) {
        int l, r; cin >> l >> r;
        int a = 0, b = 0;
        for (int i = l; i <= r; i++) {
            if (dvs[i]) {
                a = dvs[i];
                b = i - dvs[i];
                break;
            }
        }
        if (a == 0) cout << -1 << '\n';
        else cout << a << ' ' << b << '\n';
    }
}