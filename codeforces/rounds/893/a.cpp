#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        if (a > b) {
            cout << "First\n";
        } else if (a < b) {
            cout << "Second\n";
        } else {
            if (c % 2 == 1) cout << "First\n";
            else cout << "Second\n";
        }
    }
}