#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int v[6];
    for (int &v: v) cin >> v;
    int tot = accumulate(v, v + 6, 0);
    int v0 = *min_element(v, v + 6), v1 = tot, v2 = tot;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (i == j || i + j == 5) continue;
            v1 = min(v1, v[i] + v[j]);
            for (int k = 0; k < 6; k++) {
                if (i == k || i + k == 5 || j == k || j + k == 5) continue;
                v2 = min(v2, v[i] + v[j] + v[k]);
            }
        }
    }
    if (n == 1) cout << tot - *max_element(v, v + 6) << '\n';
    else cout << ll(n - 2) * (5 * n - 6) * v0 + 4 * v2 + (2 * n - 3) * 4 * v1 << '\n';
}