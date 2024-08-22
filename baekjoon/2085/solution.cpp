#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s; cin >> s;
    int n = s.size();
    if (n <= 1 || s[0] == '0') {
        cout << (n > 1 && s[1] != '0') << '\n';
        return 0;
    }
    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] >= s.back()) {
            ans = 0;
            break;
        }
    }
    for (int l = 2; l < n; l++) {
        if (s[n - l] == '0') continue;
        vector<int> cnt(n + 1);
        cnt[0] = 1;
        for (int i = 1; i <= n - l; i++) {
            cnt[i] = cnt[i - 1];
            if (i >= l && s[i - l] != '0' && s.substr(i - l, i) < s.substr(n - l, n)) cnt[i] += cnt[i - l];
            for (int j = max(0, i - l + 1); j < i - 1; j++) {
                if (s[j] != '0') cnt[i] += cnt[j];
            }
        }
        ans += cnt[n - l];
    }
    cout << ans << '\n';
}