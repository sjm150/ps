#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        ll ans = n * ll(n + 1) / 2;
        int pre = -1;
        for (int i = 1; i < n; i++) {
            if (s[i - 1] != s[i]) {
                if (pre < 0) {
                    pre = i - 1;
                } else {
                    ans -= (i - pre) / 2;
                }
            } else {
                pre = -1;
            }
        }
        vector<int> d(n);
        d[0] = (s[0] == '0' ? -1 : 1);
        for (int i = 1; i < n; i++) d[i] = (s[i] == '0' ? -1 : 1) + d[i - 1];
        int cnt[3] = {};
        cnt[0] = 1;
        for (int d: d) {
            int r = (d % 3 + 3) % 3;
            ans -= cnt[r];
            cnt[r]++;
        }
        cout << ans << '\n';
    }
}