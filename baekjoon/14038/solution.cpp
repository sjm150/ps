#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    char a[6];
    for (auto &a: a) cin >> a;
    int cnt = count(a, a + 6, 'W');
    if (cnt > 4) cout << 1 << '\n';
    else if (cnt > 2) cout << 2 << '\n';
    else if (cnt > 0) cout << 3 << '\n';
    else cout << -1 << '\n';
}