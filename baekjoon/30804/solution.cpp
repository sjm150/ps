#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> s(n);
    for (int &s: s) cin >> s;

    int l = 0, r = 0, k = 1;
    int ans = 1;
    vector<int> cnt(10, 0);
    cnt[s[0]] = true;
    for (;;) {
        if (k <= 2) {
            r++;
            if (r == n) break;
            if (!cnt[s[r]]) k++;
            cnt[s[r]]++;
            if (k <= 2) ans = max(ans, r - l + 1);
        } else {
            cnt[s[l]]--;
            if (!cnt[s[l]]) k--;
            l++;
        }
    }

    cout << ans << '\n';
}