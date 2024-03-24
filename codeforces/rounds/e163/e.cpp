#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        for (int s = 1; s <= n; s += k) {
            int e = min(s + k, n + 1);
            int m = (s + e) / 2;
            for (int i = m; i < e; i++) cout << i << ' ';
            for (int i = s; i < m; i++) cout << i << ' ';
        }
        cout << '\n';
        cout << (n + k - 1) / k << '\n';
        int c = 1;
        for (int s = 1; s <= n; s += k) {
            int e = min(s + k, n + 1);
            for (int i = s; i < e; i++) cout << c << ' ';
            c++;
        }
        cout << '\n';
    }
}