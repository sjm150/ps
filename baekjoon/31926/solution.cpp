#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int ans = 9;
    for (int i = 1; i <= n; i *= 2) ans++;
    cout << ans << '\n';
}