#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        if ((a + b) % 2) cout << "Alice\n";
        else cout << "Bob\n";
    }
}