#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    int a, b, c;
    a = b = c = n / 3;
    if (n % 3 == 1) c++;
    else if (n % 3 == 2) b++, c++;

    if (a * b + a * c + b * c < k) {
        cout << -1 << '\n';
        return 0;
    }

    for (; k >= b + c && a; k -= b + c, a--) cout << 'A';
    for (; k >= c && b; k -= c, b--) cout << 'B';
    for (; k < c; c--) cout << 'C';
    if (k) {
        if (b) {
            cout << 'B';
            k -= c;
            b--;
        } else {
            cout << 'A';
            k -= c;
            a--;
        }
    }
    while (c--) cout << 'C';
    while (b--) cout << 'B';
    while (a--) cout << 'A';
    cout << '\n';
}