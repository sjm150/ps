#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int ans = 1e9;
    if (n % 2) {
        if (n >= 5) ans = min(ans, 1 + (n - 5) / 10 * 2 + (n - 5) % 10 / 2);
    } else {
        ans = min(ans, n / 10 * 2 + n % 10 / 2);
    }
    cout << (ans < int(1e9) ? ans : -1) << '\n';
}