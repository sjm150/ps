#include <bits/stdc++.h>
using namespace std;
const int inf = 123456789;

int n;
int d[20][20];
int res[1 << 20];

int cost(int bm, int l) {
    if (l < 0) return 0;
    if (res[bm]) return res[bm];
    int& cache = res[bm];
    cache = inf;
    int rem = bm;
    while (rem) {
        int b = rem & -rem;
        cache = min(cache, cost(bm - b, l - 1) + d[l][__builtin_ctz(b)]);
        rem -= b;
    }
    return cache;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }
    cout << cost((1 << n) - 1, n - 1) << '\n';
}