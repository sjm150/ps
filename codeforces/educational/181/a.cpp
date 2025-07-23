#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string s;
        cin >> s;
        for (char c: s) {
            if (c == 'T') cout << 'T';
        }
        for (char c: s) {
            if (c != 'T') cout << c;
        }
        cout << '\n';
    }
}