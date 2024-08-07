#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    for (int i = 1; i <= min(n, m); i++) {
        bool poss = (n % i == 0) && (m % i == 0);
        for (int j = 0; poss && j < n; j++) {
            if (s[j] != s[j % i]) poss = false;
        }
        for (int j = 0; poss && j < m; j++) {
            if (t[j] != s[j % i]) poss = false;
        }
        if (poss) {
            for (int j = 0; j < i; j++) cout << s[j];
            cout << '\n';
            return 0;
        }
    }
    cout << "No solution\n";
}