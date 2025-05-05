#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        vector<tuple<int, int, int>> ord;
        int cnt = 1;
        for (int i = 1; i <= n; i++) {
            if (i == n || a[i - 1] != a[i]) {
                ord.emplace_back(a[i - 1], i - cnt, i - 1);
                cnt = 1;
            } else {
                cnt++;
            }
        }
        sort(ord.begin(), ord.end(), greater<tuple<int, int, int>>());

        vector<bool> p(n, false);
        int ans = 0;
        for (auto [a, l, r]: ord) {
            if (!(l > 0 && p[l - 1]) && !(r < n - 1 && p[r + 1])) ans++;
            p[l] = p[r] = true;
        }
        cout << ans << '\n';
    }
}