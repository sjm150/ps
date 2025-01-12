#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, a, b; cin >> n >> a >> b;
        cout << (abs(a - b) % 2 ? "NO\n" : "YES\n");
    }
}