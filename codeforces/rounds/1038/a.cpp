#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << (n == 1 || m == 1 || (n == 2 && m == 2) ? "NO\n" : "YES\n");
    }
}