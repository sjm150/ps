#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    n = 1 << n;
    vector<int> r(n);
    for (int &r: r) cin >> r;
    sort(r.begin(), r.end());
    int ans = 0;
    for (int sz = n / 2; sz; sz /= 2) {
        for (int i = n - sz * 2, j = n - sz; i < n - sz && j < n; i++) {
            if (r[j] - r[i] <= k) {
                ans++;
                j++;
            }
        }
    }
    cout << ans << '\n';
}