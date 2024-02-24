#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int a, b, c, n; cin >> a >> b >> c >> n;
    if (c >= a && (a - c) * n + b <= 0) cout << 1 << '\n';
    else cout << 0 << '\n';
}