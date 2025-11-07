#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << "Pairs for " << n << ':';
        if (n > 2) cout << ' ' << 1 << ' ' << n - 1;
        for (int i = 2; i < n - i; i++) cout << ", " << i << ' ' << n - i;
        cout << '\n';
    }
}