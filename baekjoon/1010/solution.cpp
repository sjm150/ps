#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        long long comb = 1;
        for (int i = 0; i < n; i++) {
            comb *= m - i;
            comb /= i + 1;
        }
        cout << comb << '\n';
    }
}