#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s;
    int x, ans = 0;
    while (cin >> s) {
        cin >> x;
        ans += x * (s[0] == 'E' ? 21 : 17);
    }
    cout << ans << '\n';
}