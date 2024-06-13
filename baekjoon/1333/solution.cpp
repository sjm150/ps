#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, l, d; cin >> n >> l >> d;
    for (int i = l; i <= n * (l + 5) + d; i++) {
        if ((i >= n * (l + 5) || (i - l) % (l + 5) < 5) && i % d == 0) {
            cout << i << '\n';
            break;
        }
    }
}