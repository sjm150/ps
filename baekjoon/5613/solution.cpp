#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int ans;
    cin >> ans;
    for (;;) {
        char c;
        cin >> c;
        if (c == '=') break;
        int x;
        cin >> x;
        if (c == '+') ans += x;
        else if (c == '-') ans -= x;
        else if (c == '*') ans *= x;
        else ans /= x;
    }
    cout << ans << '\n';
}