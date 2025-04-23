#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    char a, b;
    for (int tc = 1; ; tc++) {
        cin >> a >> b;
        if (a == '#') break;
        int n; cin >> n;
        cin.ignore(1);
        vector<string> s(n);
        for (auto &s: s) getline(cin, s);
        cout << "Case " << tc << '\n';
        for (auto &s: s) {
            for (char c: s) {
                if (c == a || c - 'A' + 'a' == a || c == b || c - 'A' + 'a' == b) cout << '_';
                else cout << c;
            }
            cout << '\n';
        }
        cout << '\n';
    }
}