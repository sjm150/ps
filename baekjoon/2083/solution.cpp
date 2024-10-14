#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (;;) {
        string s; cin >> s;
        int a, b; cin >> a >> b;
        if (s[0] == '#') break;
        cout << s << ' ' << (a > 17 || b >= 80 ? "Senior\n" : "Junior\n");
    }
}