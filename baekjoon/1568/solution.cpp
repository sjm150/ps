#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int ans = 0;
    while (n) {
        int x = 1;
        while ((x + 1) * (x + 2) / 2 <= n) x++;
        ans += x;
        n -= x * (x + 1) / 2;
    }
    cout << ans << '\n';
}