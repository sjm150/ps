#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        while (k--) cout << 1 << ' ';
        cout << '\n';
    } else if (n * k == 2) {
        cout << 1 << ' ' << 2 << '\n';
    } else {
        cout << -1 << '\n';
    }
}