#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    typedef pair<int, int> pi;
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> c(n), rt(r);
    vector<pi> qp(m);
    for (int &c: c) cin >> c;
    for (auto &[q, p]: qp) cin >> q >> p;
    for (auto &r: rt) cin >> r;

    sort(c.begin(), c.end(), greater<int>());
    sort(qp.begin(), qp.end(), [](pi a, pi b) { return a.second > b.second; });
    sort(rt.begin(), rt.end(), greater<int>());

    int idx = 0;
    ll sum = accumulate(rt.begin(), rt.begin() + min(n, r), 0ll), ans = sum;
    for (int i = 0; i < n; i++) {
        if (n - 1 - i < r) sum -= rt[n - 1 - i];
        while (idx < m && c[i]) {
            if (qp[idx].first < c[i]) {
                sum += ll(qp[idx].first) * qp[idx].second;
                c[i] -= qp[idx].first;
                idx++;
            } else {
                sum += ll(qp[idx].second) * c[i];
                qp[idx].first -= c[i];
                c[i] = 0;
            }
        }
        ans = max(ans, sum);
    }
    cout << ans << '\n';
}