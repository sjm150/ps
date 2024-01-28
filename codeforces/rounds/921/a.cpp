#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cout << char('a' + j);
        }
        cout << '\n';
    }
}