#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        map<int, int> cnt;
        for (int a: a) cnt[a]++;
        int sum = 0;
        vector<pair<int, int>> psum;
        for (auto &[a, cnt]: cnt) {
            sum += cnt;
            psum.emplace_back(a, sum);
        }
        int sz = psum.size();

        int ans = 0;
        for (int i = 0; i < sz; i++) {
            int c = cnt[psum[i].first], lsum = psum[i].second - c, rsum = psum.back().second - lsum - c;
            if (lsum + c + k >= rsum && lsum <= rsum + c + k) {
                ans++;
            }
        }
        for (int i = 0; i < sz - 1; i++) {
            int lsum = psum[i].second, rsum = psum.back().second - lsum;
            if (abs(lsum - rsum) <= k) {
                ans += psum[i + 1].first - psum[i].first - 1;
            }
        }
        cout << ans << '\n';
    }
}