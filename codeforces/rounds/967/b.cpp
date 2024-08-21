#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n % 2) {
            vector<int> p(n);
            int x = 1;
            for (int i = 0; i < n; i += 2) p[i] = x++;
            for (int i = n - 2; i > 0; i -= 2) p[i] = x++;
            for (int p: p) cout << p << ' ';
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}