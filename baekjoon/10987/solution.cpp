#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int ans = 0;
    for (char c: s) ans += c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    cout << ans << '\n';
}