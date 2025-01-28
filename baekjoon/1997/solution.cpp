#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int m, n; cin >> m >> n;
    int sum = 0, mn = -1;
    int i = 1;
    while (i * i < m) i++;
    for (; i * i <= n; i++) {
        if (mn < 0) mn = i * i;
        sum += i * i;
    }
    if (mn < 0) {
        cout << -1 << '\n';
    } else {
        cout << sum << '\n';
        cout << mn << '\n';
    }
}