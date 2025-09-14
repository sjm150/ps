#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k, s;
    cin >> n >> k >> s;
    vector<pair<int, int>> cnt(n);
    for (auto &[x, c]: cnt) cin >> x >> c;
    sort(cnt.begin(), cnt.end());
    int m = lower_bound(cnt.begin(), cnt.end(), make_pair(s, 0)) - cnt.begin();
    int ans = 0, sum = 0;
    auto iter = [&](int i) {
        auto [x, c] = cnt[i];
        ans += ((sum + c + k - 1) / k - (sum + k - 1) / k) * abs(x - s) * 2;
        sum += c;
    };
    for (int i = 0; i < m; i++) iter(i);
    sum = 0;
    for (int i = n - 1; i >= m; i--) iter(i);
    cout << ans << '\n';
}