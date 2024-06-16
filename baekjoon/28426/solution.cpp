#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    if (n == 1) {
        cout << 2 << '\n';
    } else if (n == 2) {
        cout << 2 << ' ' << 4 << '\n';
    } else {
        for (int i = 1; i < n; i++) cout << 2 * i << ' ';
        cout << (n % 2 ? n : n - 1) << '\n';
    }
}