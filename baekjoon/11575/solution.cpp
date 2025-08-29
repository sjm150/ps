#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        for (char &c: s) c = ((c - 'A') * a + b) % 26 + 'A';
        cout << s << '\n';
    }
}