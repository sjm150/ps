#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s; cin >> s;
    int n = s.size();
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) cout << s[i - 1];
    }
    cout << s[n - 1] << '\n';
}