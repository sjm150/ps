#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s, t; cin >> s >> t;
    string ans;
    for (char c: s) {
        ans.push_back(c);
        if (ans.size() >= t.size() && ans.substr(ans.size() - t.size(), t.size()) == t) ans.resize(ans.size() - t.size());
    }
    cout << ans << '\n';
}