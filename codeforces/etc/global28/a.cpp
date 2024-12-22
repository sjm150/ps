#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        cout << (x % 33 == 0 ? "YES\n" : "NO\n");
    }
}