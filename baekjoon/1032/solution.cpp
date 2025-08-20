#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<string> s(n);
    for (auto &s: s) cin >> s;
    string ans = s[0];
    for (auto &s: s) {
        for (int i = 0; i < int(ans.size()); i++) {
            if (ans[i] != s[i]) ans[i] = '?';
        }
    }
    cout << ans << '\n';
}