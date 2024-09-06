#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int x; cin >> x;
    int ans = 0;
    for (; x; x /= 2) ans += x % 2;
    cout << ans << '\n';
}