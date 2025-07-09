#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (;;) {
        string s;
        getline(cin, s);
        if (s == "END") break;
        reverse(s.begin(), s.end());
        cout << s << '\n';
    }
}