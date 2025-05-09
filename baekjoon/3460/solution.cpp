#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; n; i++, n /= 2) {
            if (n & 1) cout << i << ' ';
        }
        cout << '\n';
    }
}