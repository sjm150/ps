#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, c, k; cin >> n >> c >> k;
    vector<int> r(k + 1), rnk(n);
    for (int i = 1; i <= k; i++) cin >> r[i];
    r[0] = 0;
    sort(r.begin(), r.end());
    iota(rnk.begin(), rnk.end(), 1);
    for (int i = 0; i < c - 1; i++) {
        for (int r: rnk) cout << r << ' ';
        cout << '\n';
    }
    for (int i = 0; i < k; i++) swap(rnk[r[i]], rnk[r[i + 1] - 1]);
    if (r[k] != n) rnk[r[k]] = 1e6;
    for (int r: rnk) cout << r << ' ';
    cout << '\n';
}