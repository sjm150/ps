#include <bits/stdc++.h>
using namespace std;

int f[20][200001];

void init(int m) {
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = f[i - 1][f[i - 1][j]];
        }
    }
}

int getfnx(int n, int x) {
    for (int i = 19; i >= 0; i--) {
        if (n >= (1 << i)) {
            n -= (1 << i);
            x = f[i][x];
        }
    }
    return x;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int m; cin >> m;
    for (int i = 1; i <= m; i++) cin >> f[0][i];
    init(m);
    int q; cin >> q;
    while (q--) {
        int n, x; cin >> n >> x;
        cout << getfnx(n, x) << '\n';
    }
}