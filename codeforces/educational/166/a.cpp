#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        auto digit = [](char c) { return '0' <= c && c <= '9'; };
        auto lettr = [](char c) { return 'a' <= c && c <= 'z'; };

        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (digit(s[i])) {
                if (lettr(s[i - 1]) || s[i - 1] > s[i]) {
                    ok = false;
                    break;
                }
            } else if (lettr(s[i])) {
                if (lettr(s[i - 1]) && s[i - 1] > s[i]) {
                    ok = false;
                    break;
                }
            } else {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}