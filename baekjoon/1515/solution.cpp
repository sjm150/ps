#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int n = s.size(), ans = 1, idx = 0;
    for (; idx < n; ans++) {
        for (char c: to_string(ans)) {
            if (c == s[idx]) {
                idx++;
                if (idx == n) break;
            }
        }
        if (idx == n) break;
    }
    cout << ans << '\n';
}