#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        string rev = s;
        reverse(rev.begin(), rev.end());
        if (s <= rev) cout << s << '\n';
        else cout << rev << s << '\n';
    }
}