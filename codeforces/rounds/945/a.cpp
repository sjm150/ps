#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int p[3];
        for (int &p: p) cin >> p;
        sort(p, p + 3);

        if ((p[0] + p[1] + p[2]) & 1) {
            cout << -1 << '\n';
            continue;
        }

        if (p[2] >= p[0] + p[1]) cout << p[0] + p[1] << '\n';
        else cout << (p[0] + p[1] + p[2]) / 2 << '\n';
    }
}