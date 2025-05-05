#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int i; cin >> i;
        string s; cin >> s;
        s.erase(s.begin() + i - 1);
        cout << s << '\n';
    }
}