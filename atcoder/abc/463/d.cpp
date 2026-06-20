#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> rl(n);
    for (auto &[r, l]: rl) cin >> l >> r;
    sort(rl.begin(), rl.end());

    int l = 1, r = 1e9 + 1;
    while (l < r) {
        int m = (l + r) / 2;
        int cnt = 0, pre = -1;
        for (auto [r, l]: rl) {
            if (pre <= l) {
                pre = r + m;
                cnt++;
            }
        }
        if (cnt >= k) l = m + 1;
        else r = m;
    }

    cout << (r > 1 ? r - 1 : -1) << '\n';
}