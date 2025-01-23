#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int x, n; cin >> x >> n;
    if (n == 1 && x >= 0) cout << 0 << '\n';
    else if (n == 1 && x < 0) cout << "INFINITE\n";
    else if (n % 2) cout << "ERROR\n";
    else if (x <= 0) cout << 0 << '\n';
    else if (n == 0) cout << "INFINITE\n";
    else cout << max(0, (x - 1) / (n / 2)) << '\n';
}