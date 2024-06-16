#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, a, b; cin >> n >> a >> b;
        if (a >= b) {
            cout << ll(a) * n << '\n';
        } else {
            if (b - n + 1 >= a) {
                cout << ll(b) * n - ll(n - 1) * n / 2 << '\n';
            } else {
                cout << ll(a) * n + ll(b - a) * (b - a + 1) / 2 << '\n';
            }
        }
    }
}