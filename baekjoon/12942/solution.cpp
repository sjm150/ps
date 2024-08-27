#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, q; cin >> n >> q;
    int e = 0, o = 0;
    while (q--) {
        int c; cin >> c;
        if (c == 1) {
            int x; cin >> x;
            e = (e + x + n) % n;
            o = (o + x + n) % n;
        } else {
            if (e % 2) {
                e = (e - 1 + n) % n;
                o = (o + 1) % n;
            } else {
                e = (e + 1) % n;
                o = (o - 1 + n) % n;
            }
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i += 2) ans[(i + e) % n] = i + 1;
    for (int i = 1; i < n; i += 2) ans[(i + o) % n] = i + 1;
    for (int a: ans) cout << a << ' ';
    cout << '\n';
}