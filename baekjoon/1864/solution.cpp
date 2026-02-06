#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    map<char, int> v = {{'/', -1}};
    for (int i = 0; i < 8; i++) v.emplace("-\\(@?>&%"[i], i);
    for (;;) {
        string s;
        cin >> s;
        if (s[0] == '#') break;
        int ans = 0;
        for (char c: s) ans = ans * 8 + v[c];
        cout << ans << '\n';
    }
}