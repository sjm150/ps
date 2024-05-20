#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<bool> occ(26, false);
        for (char c: s) occ[c - 'a'] = true;
        string r = "";
        for (int i = 0; i < 26; i++) {
            if (occ[i]) r += i + 'a';
        }

        vector<char> m(26, ' ');
        for (int i = 0; i < r.size(); i++) {
            m[r[i] - 'a'] = r[r.size() - 1 - i];
        }

        for (char c: s) cout << m[c - 'a'];
        cout << '\n';
    }
}