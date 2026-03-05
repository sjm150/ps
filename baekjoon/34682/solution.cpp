#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int sz = s.size();
    bool ok = sz % 2 == 0;
    for (int i = 3; ok && i < sz; i += 2) {
        if (s[i - 2] == s[i]) ok = false;
    }
    for (int i = 0; ok && i < sz; i += 2) {
        if (s[i] == '0') ok = false;
    }
    if (ok && s[1] == '0') ok = false;
    if (ok) {
        for (int i = 0; i < sz; i += 2) {
            int c = s[i] - '0';
            while (c--) cout << s[i + 1];
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
}