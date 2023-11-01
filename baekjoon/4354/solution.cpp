#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    while (true) {
        string s; cin >> s;
        if (s[0] == '.') break;
        vector<int> pi(s.size());
        int i = 1, j = 0;
        pi[0] = -1;
        while (i < s.size()) {
            if (s[i] == s[j]) {
                pi[i] = pi[j];
            } else {
                pi[i] = j;
                while (j >= 0 && s[i] != s[j]) j = pi[j];
            }
            i++, j++;
        }
        int l = s.size() - j;
        if (s.size() % l == 0) cout << s.size() / l << '\n';
        else cout << "1\n";
    }
}