#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<int> a(n + 1);
        vector<int> x(q + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= q; i++) cin >> x[i];

        vector<int> div(31), add(31);
        iota(div.begin(), div.end(), 0);
        fill(add.begin(), add.end(), 0);
        for (int i = 1; i <= q; i++) {
            for (int j = 1; j <= 30; j++) {
                if (div[j] >= x[i]) {
                    div[j] = x[i] - 1;
                    add[j] += (1 << div[j]);
                }
            }
        }

        for (int i = 1; i <= n; i++) cout << a[i] + add[__builtin_ctz(a[i])] << ' ';
        cout << '\n';
    }
}