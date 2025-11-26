#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef pair<int, int> pi;
    int n, m, k;
    cin >> n >> m >> k;
    vector<pi> ab(n);
    for (auto &[a, b]: ab) cin >> a >> b;
    sort(ab.begin(), ab.end(), [](pi a, pi b) { return a.second > b.second; });
    sort(ab.begin() + k, ab.end(), [](pi a, pi b) { return a.first > b.first; });
    long long ans = 0;
    for (int i = 0; i < m + k; i++) ans += ab[i].first;
    cout << ans << '\n';
}