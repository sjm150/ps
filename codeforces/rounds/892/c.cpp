#include <bits/stdc++.h>
using namespace std;

int sqrsum(int n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int maxs = 0;
        for (int i = 0; i < n; i++) {
            int sum = sqrsum(i);
            int maxv = 0;
            for (int j = i + 1; j <= n; j++) {
                int v = j * (n + 1 - j + i);
                sum += v;
                maxv = max(maxv, v);
            }
            maxs = max(maxs, sum - maxv);
        }
        cout << maxs << '\n';
    }
}