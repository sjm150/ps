#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    cout << (n == 2 ? 1 : (n - 3) / 2 + 2) << ' ';
    if (n % 3 == 0) cout << n / 3 * 2 << '\n';
    else if (n % 3 == 1) cout << (n - 4) / 3 * 2 + 2 << '\n';
    else if (n % 3 == 2) cout << (n - 2) / 3 * 2 + 1 << '\n';
}