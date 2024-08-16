#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int l, r, ll, rr; cin >> l >> r >> ll >> rr;
        int s = max(l, ll) - (l != ll);
        int e = min(r, rr) + (r != rr);
        cout << max(1, e - s) << '\n';
    }
}