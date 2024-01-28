#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k, m; cin >> n >> k >> m;
        string s; cin >> s;

        set<char> alp;
        string ans;
        for (char c: s) {
            alp.insert(c);
            if (alp.size() == k) {
                alp = set<char>();
                ans += c;
            }
        }

        if (ans.size() >= n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
            for (int i = 0; i < k; i++) {
                if (alp.find('a' + i) == alp.end()) {
                    ans += 'a' + i;
                    break;
                }
            }
            while (ans.size() < n) ans += 'a';
            cout << ans << '\n';
        }
    }
}