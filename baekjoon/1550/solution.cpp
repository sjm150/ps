#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    auto val = [](char c) {
        if (c >= 'A') return c - 'A' + 10;
        else return c - '0';
    };
    string s; cin >> s;
    int ans = 0;
    for (char c: s) ans = ans * 16 + val(c);
    cout << ans << '\n';
}