#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n & 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << "AA";
            n = n / 2 - 1;
            while (n--) cout << "BAA";
            cout << '\n';
        }
    }
}