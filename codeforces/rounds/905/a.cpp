#include <bits/stdc++.h>
using namespace std;

int cnt[26];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        fill(cnt, cnt + 26, 0);
        for (char c: s) cnt[c - 'a']++;
        int odd = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) odd++;
        }
        if (((n - k) % 2 == 0 && odd <= k && (k - odd) % 2 == 0)
            || ((n - k) % 2 == 1 && odd - k <= 1 && (k - odd) % 2)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}