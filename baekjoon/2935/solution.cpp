#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string a, o, b; cin >> a >> o >> b;
    if (o[0] == '+') {
        string ans(max(a.size(), b.size()), '0');
        if (a.size() == b.size()) {
            ans[0] = '2';
        } else {
            ans[0] = '1';
            ans[ans.size() - min(a.size(), b.size())] = '1';
        }
        cout << ans << '\n';
    } else {
        string ans(a.size() + b.size() - 1, '0');
        ans[0] = '1';
        cout << ans << '\n';
    }
}