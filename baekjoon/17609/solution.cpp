#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        auto chk = [&](int l, int r) {
            for (int i = 0; i + l < r - i; i++) {
                if (s[i + l] != s[r - i]) return false;
            }
            return true;
        };
        auto solve = [&]() {
            for (int i = 0; i < n - 1 - i; i++) {
                if (s[i] != s[n - 1 - i]) {
                    if (chk(i, n - 2 - i) || chk(i + 1, n - 1 - i)) return 1;
                    else return 2;
                }
            }
            return 0;
        };
        cout << solve() << '\n';
    }
}