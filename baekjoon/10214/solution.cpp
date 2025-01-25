#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int a = 0, b = 0;
        for (int i = 0; i < 9; i++) {
            int aa, bb; cin >> aa >> bb;
            a += aa;
            b += bb;
        }
        if (a > b) cout << "Yonsei\n";
        else if (a < b) cout << "Korea\n";
        else cout  << "Draw\n";
    }
}