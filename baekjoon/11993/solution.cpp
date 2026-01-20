#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int n;
    cin >> n;
    vector<int> c(n);
    for (int &c: c) cin >> c;

    auto p = c;
    p.resize(2 * n);
    copy(c.begin(), c.end(), p.begin() + n);
    p[0]--;
    for (int i = 1; i < 2 * n; i++) p[i] += p[i - 1] - 1;

    int st = (min_element(p.begin(), p.end()) - p.begin() + 1) % n;
    queue<pair<int, int>> q;
    ll ans = 0;
    for (int i = 0, idx = st; i < n; i++, idx++) {
        if (idx == n) idx = 0;
        if (c[idx]) q.emplace(i, c[idx]);
        ans += ll(i - q.front().first) * (i - q.front().first);
        q.front().second--;
        if (!q.front().second) q.pop();
    }

    cout << ans << '\n';
}