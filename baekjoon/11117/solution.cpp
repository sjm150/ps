#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        vector<int> mx(26, 0);
        string s; cin >> s;
        for (char c: s) mx[c - 'A']++;
        int w; cin >> w;
        while (w--) {
            vector<int> cnt(26, 0);
            string s; cin >> s;
            for (char c: s) cnt[c - 'A']++;
            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (mx[i] < cnt[i]) {
                    ok = false;
                    break;
                }
            }
            cout << (ok ? "YES\n" : "NO\n");
        }
    }
}