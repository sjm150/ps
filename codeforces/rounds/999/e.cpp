#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int inf = 1 << 30;
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> a(n), b(m);
        for (int &a: a) cin >> a;
        for (int &b: b) cin >> b;

        vector<vector<int>> mn(n, vector<int>(m + 1, inf));
        for (int i = 0; i < n; i++) {
            function<void(int, int, int)> sel = [&](int cur, int idx, int cnt) {
                if (idx == m) {
                    mn[i][cnt] = min(mn[i][cnt], cur);
                    return;
                }
                sel(cur, idx + 1, cnt);
                sel(cur & b[idx], idx + 1, cnt + 1);
            };
            sel(a[i], 0, 0);
        }

        long long ans = accumulate(a.begin(), a.end(), 0ll);
        priority_queue<tuple<int, int, int>> pq;
        for (int i = 0; i < n; i++) pq.emplace(mn[i][0] - mn[i][1], i, 0);
        while (k--) {
            auto [d, i, cnt] = pq.top(); pq.pop();
            ans -= d;
            if (cnt < m - 1) pq.emplace(mn[i][cnt + 1] - mn[i][cnt + 2], i, cnt + 1);
        }

        cout << ans << '\n';
    }
}