#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s; cin >> s;
    int n; cin >> n;
    int ans = 0;
    for (char c: s) {
        ans *= n;
        if ('0' <= c && c <= '9') ans += c - '0';
        else ans += c - 'A' + 10;
    }
    cout << ans << '\n';
}