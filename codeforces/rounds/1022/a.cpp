#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int mx = 0;
        for (int i = 1; i <= n; i++) mx += abs(n - 2 * i + 1);
        cout << mx / 2 + 1 << '\n';
    }
}