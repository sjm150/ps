#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> vck(n);
    for (auto &[v, c, k]: vck) cin >> v >> c >> k;

    vector<int> dp(m + 1, 0);
    auto iter = [&](int v, int c) {
        for (int i = m; i >= v; i--) dp[i] = max(dp[i], dp[i - v] + c);
    };

    for (auto [v, c, k]: vck) {
        iter(v, c);
        for (int i = 1; i * 2 <= k; i *= 2) {
            iter(v * i, c * i);
            if (k & i) iter(v * i, c * i);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';
}