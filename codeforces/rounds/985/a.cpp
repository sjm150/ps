#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int l, r, k; cin >> l >> r >> k;
        cout << max(0, r / k - l + 1) << '\n';
    }
}