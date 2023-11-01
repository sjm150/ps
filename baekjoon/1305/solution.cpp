#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int l; cin >> l;
    string s; cin >> s;
    vector<int> pi(l);
    int i = 1, j = 0;
    pi[0] = -1;
    while (i < l) {
        if (s[i] == s[j]) {
            pi[i] = pi[j];
        } else {
            pi[i] = j;
            while (j >= 0 && s[i] != s[j]) j = pi[j];
        }
        i++, j++;
    }
    cout << l - j << '\n';
}