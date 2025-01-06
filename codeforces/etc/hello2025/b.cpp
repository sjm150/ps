#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            cnt[a]++;
        }
        vector<int> cs;
        for (auto [a, cnt]: cnt) cs.push_back(cnt);
        sort(cs.begin(), cs.end());
        int ans = 0;
        for (int c: cs) {
            if (c <= k) {
                k -= c;
                continue;
            }
            ans++;
        }
        if (ans == 0) ans++;
        cout << ans << '\n';
    }
}