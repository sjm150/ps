#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || s[i] == s[i + 1]) {
                cout << s.substr(0, i + 1) << char((s[i] - 'a' + 1) % 26 + 'a') << s.substr(i + 1, n) << '\n';
                break;
            }
        }
    }
}