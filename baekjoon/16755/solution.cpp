#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int cur = 0, ans = 0;
    for (char c: s) {
        if (c == 'H' && cur == 0) cur++;
        else if (c == 'O' && cur == 1) cur++;
        else if (c == 'N' && cur == 2) cur++;
        else if (c == 'I' && cur == 3) cur = 0, ans++;
    }
    cout << ans << '\n';
}