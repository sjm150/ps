#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int ds, ys, dm, ym;
    cin >> ds >> ys >> dm >> ym;
    for (int i = 0;; i++) {
        if ((ds + i) % ys == 0 && (dm + i) % ym == 0) {
            cout << i << '\n';
            break;
        }
    }
}