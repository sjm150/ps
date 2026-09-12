#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (i) cout << 'o';
        cout << s[i];
    }
    cout << '\n';
}