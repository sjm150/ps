#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s; cin >> s;
    char p = 0;
    int ans = 0;
    for (char c: s) {
        ans += p == c ? 5 : 10;
        p = c;
    }
    cout << ans << '\n';
}