#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int q = n / 5;
        int r = n % 5;
        string v = "aeiou";
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < q; j++) cout << v[i];
            if (i < r) cout << v[i];
        }
        cout << '\n';
    }
}