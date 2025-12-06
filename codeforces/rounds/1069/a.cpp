#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string s, t;
        cin >> s >> t;

        vector<int> cnt(26, 0);
        for (char c: t) cnt[c - 'a']++;
        bool ok = true;
        for (char c: s) {
            if (cnt[c - 'a'] == 0) {
                ok = false;
                break;
            }
            cnt[c - 'a']--;
        }

        if (!ok) {
            cout << "Impossible\n";
            continue;
        }

        int idx = 0, len = s.size();
        string ans;
        for (int i = 0; i < 26; i++) {
            while (idx < len && s[idx] - 'a' <= i) ans += s[idx++];
            while (cnt[i]--) ans += i + 'a';
        }
        cout << ans << '\n';
    }
}