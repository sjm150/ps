#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        if (n == 2) {
            cout << (s[0] == 'A' ? "Alice\n" : "Bob\n");
            continue;
        }

        int cnt = 0;
        for (char c: s) {
            if (c == 'A') cnt++;
        }
        cout << (cnt >= n - 1 || (s[n - 2] == 'A' && s[n - 1] == 'A') || (s[0] == 'A' && s[n - 1] == 'A') ? "Alice\n" : "Bob\n");
    }
}