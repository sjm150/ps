#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s, t; cin >> s >> t;
        string ss = s, tt = t;
        for (int i = 0; i < n - 2; i++) {
            if (s[i] == '0' && s[i + 2] == '0') tt[i + 1] = '1';
        }
        for (int i = 0; i < n - 2; i++) {
            if (tt[i] == '1' && tt[i + 2] == '1') ss[i + 1] = '1';
        }

        vector<int> cnt(n + 1);
        cnt[0] = 0;
        for (int i = 1; i <= n; i++) cnt[i] = cnt[i - 1] + (ss[i - 1] == '1');

        int q; cin >> q;
        while (q--) {
            int l, r; cin >> l >> r;
            l--, r--;
            int ll = l, rr = r;
            if (t[ll] == '0') ll++;
            if (t[rr] == '0') rr--;

            int ans = 0;
            if (ll >= rr - 1) {
                for (int i = l; i <= r; i++) ans += s[i] == '1';
            } else {
                ans = cnt[rr] - cnt[ll + 1];
                for (int i = l; i <= ll; i++) ans += s[i] == '1';
                for (int i = rr; i <= r; i++) ans += s[i] == '1';
            }
            cout << ans << '\n';
        }
    }
}