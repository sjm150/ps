#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s;
    while (cin >> s) {
        int cnt = 1, ans = 1;
        for (int i = 1; i < int(s.size()); i++) {
            if (s[i - 1] == s[i]) {
                cnt++;
                ans = max(ans, cnt);
            } else {
                cnt = 1;
            }
        }
        cout << ans << '\n';
    }
}