#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        bool w = s[0] == '1' || s[n - 1] == '1';
        for (int i = 1; i < n; i++) {
            if (s[i - 1] == '1' && s[i] == '1') w = true;
        }
        cout << (w ? "YES\n" : "NO\n");
    }
}