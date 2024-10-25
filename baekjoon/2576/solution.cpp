#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n = 7;
    int sum = 0, mn = 100;
    while (n--) {
        int a; cin >> a;
        if (a % 2) {
            sum += a;
            mn = min(mn, a);
        }
    }
    if (sum) cout << sum << '\n' << mn << '\n';
    else cout << -1 << '\n';
}