#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int ncnt = 0;
        bool zero = false;
        for (int i = 1; i <= n; i++) {
            int a; cin >> a;
            if (a < 0) ncnt++;
            else if (a == 0) zero = true;
        }

        if (ncnt & 1 || zero) cout << 0 << '\n';
        else cout << 1 << '\n' << 1 << ' ' << 0 << '\n';
    }
}