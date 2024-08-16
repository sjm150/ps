#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> x(n);
        for (int &x: x) cin >> x;
        if (n == 2 && x[0] + 1 < x[1]) cout << "YES\n";
        else cout << "NO\n";
    }
}