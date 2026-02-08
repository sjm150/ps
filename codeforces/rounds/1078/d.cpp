#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (auto &a: a) {
            for (int &a: a) cin >> a;
        }

        int tot = 0;
        for (auto &a: a) tot += accumulate(a.begin(), a.end(), 0);

        int cnt = 0;
        vector<int> idx(n, m);
        for (int i = 0; i < n; i++) {
            while (cnt < tot / 2 && idx[i]) {
                idx[i]--;
                cnt += a[i][idx[i]];
            }
        }

        string ans;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            while (cur < idx[i]) {
                ans += 'R';
                cur++;
            }
            ans += 'D';
        }
        while (cur < m) {
            ans += 'R';
            cur++;
        }

        cout << (long long)(tot - cnt) * cnt << '\n';
        cout << ans << '\n';
    }
}