#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s;
    for (;;) {
        cin >> s;
        if (s[0] == '#') break;
        int x = 0, y = 0, a = 0, b = 0;
        for (char c: s) {
            if (c == 'A') {
                a++;
                if (a >= 4 && a > b + 1) {
                    x++;
                    a = 0, b = 0;
                }
            } else {
                b++;
                if (b >= 4 && b > a + 1) {
                    y++;
                    a = 0, b = 0;
                }
            }
        }
        cout << "A " << x << " B " << y << '\n';
    }
}