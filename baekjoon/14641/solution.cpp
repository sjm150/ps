#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int m, n; cin >> m >> n;
    bool conn[26][26] = {};
    for (int i = 0; i < 26; i++) conn[i][i] = true;
    while (m--) {
        char a, b; cin >> a >> b;
        conn[a - 'a'][b - 'a'] = true;
    }
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (conn[i][k] && conn[k][j]) conn[i][j] = true;
            }
        }
    }
    while (n--) {
        string s, t; cin >> s >> t;
        bool same = true;
        if (s.size() != t.size()) same = false;
        for (int i = 0; i < s.size() && same; i++) {
            if (!conn[s[i] - 'a'][t[i] - 'a']) same = false;
        }
        cout << (same ? "yes\n" : "no\n");
    }
}