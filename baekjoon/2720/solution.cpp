#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int c; cin >> c;
        int v[4] = {25, 10, 5, 1}, cnt[4];
        for (int i = 0; i < 4; i++) {
            cnt[i] = c / v[i];
            c %= v[i];
            cout << cnt[i] << ' ';
        }
        cout << '\n';
    }
}