#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s; cin >> s;
    int n = s.size() / 3;

    vector<int> ans;
    for (int i = 1; i < 3 * n - 1; i++) {
        if (s[i - 1] == s[i]) {
            if (i < 3 * n - 2 && s[i] == s[i + 1] && s[i + 1] != s[i + 2]) continue;
            ans.push_back(i + 1);
            s[i] = '0' + '1' - s[i];
            s[i + 1] = '0' + '1' - s[i + 1];
            if (ans.size() == n) break;
        }
    }

    cout << ans.size() << '\n';
    for (int a: ans) cout << a << ' ';
    cout << '\n';
}