#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (;;) {
        string s;
        getline(cin, s);
        if (s[0] == '*') break;
        vector<bool> ok(26, false);
        for (char c: s) {
            if (c != ' ') ok[c - 'a'] = true;
        }
        cout << (accumulate(ok.begin(), ok.end(), 0) == 26 ? "Y\n" : "N\n");
    }
}