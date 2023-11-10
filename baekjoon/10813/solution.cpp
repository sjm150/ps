#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> b(n + 1);
    iota(b.begin(), b.end(), 0);
    while (m--) {
        int i, j; cin >> i >> j;
        if (i == j) continue;
        b[i] ^= b[j];
        b[j] ^= b[i];
        b[i] ^= b[j];
    }
    for (int i = 1; i <= n; i++) cout << b[i] << ' ';
    cout << '\n';
}