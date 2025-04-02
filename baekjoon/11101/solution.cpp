#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string a, b; cin >> a >> b;
        map<string, int> r;
        int lst = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == ':') {
                size_t len = 0;
                r[a.substr(lst, i - lst)] = stoi(a.substr(i + 1), &len);
                i += len + 1;
                lst = i + 1;
            }
        }
        int cur = 0, ans = 1e9;
        lst = 0;
        for (int i = 0; i <= b.size(); i++) {
            if (i == b.size() || b[i] == '|') {
                cur = max(cur, r[b.substr(lst, i - lst)]);
                ans = min(ans, cur);
                cur = 0;
                lst = i + 1;
            } else if (b[i] == '&') {
                cur = max(cur, r[b.substr(lst, i - lst)]);
                lst = i + 1;
            }
        }
        cout << ans << '\n';
    }
}