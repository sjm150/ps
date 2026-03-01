#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (;;) {
        char c;
        cin >> c;
        if (c == '#') break;
        string s;
        getline(cin, s);
        int cnt = 0;
        cout << c << ' ' << count(s.begin(), s.end(), c) + count(s.begin(), s.end(), c - 'a' + 'A') << '\n';
    }
}