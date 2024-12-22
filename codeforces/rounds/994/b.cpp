#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        bool ep = false, es = false;
        if (s[0] == 'p') ep = true;
        if (s[n - 1] == 's') es = true;
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == 'p') ep = true;
            else if (s[i] == 's') es = true;
        }
        cout << (ep && es ? "NO\n" : "YES\n");
    }
}