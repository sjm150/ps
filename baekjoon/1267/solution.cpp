#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int y = 0, m = 0;
    while (n--) {
        int t; cin >> t;
        y += t / 30 * 10 + 10;
        m += t / 60 * 15 + 15;
    }
    if (y < m) cout << "Y " << y << '\n';
    else if (y > m) cout << "M " << m << '\n';
    else cout << "Y M " << y << '\n';
}