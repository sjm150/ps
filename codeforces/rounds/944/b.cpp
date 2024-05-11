#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int idx = -1;
        for (int i = 1; i < s.size(); i++) {
            if (s[0] != s[i]) {
                idx = i;
                break;
            }
        }
        if (idx >= 0) {
            cout << "YES\n";
            swap(s[0], s[idx]);
            cout << s << '\n';
        } else {
            cout << "NO\n";
        }
    }
}