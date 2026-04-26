#include <bits/stdc++.h>
using namespace std;

int rv[500001], cv[500001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    while (q--) {
        int c, i, v; cin >> c >> i >> v;
        if (c == 1) rv[i] += v;
        else cv[i] += v;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cout << rv[i] + cv[j] << ' ';
        cout << '\n';
    }
}