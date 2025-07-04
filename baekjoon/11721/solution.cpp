#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        cout << s[i];
        if (i % 10 == 9) cout << '\n';
    }
}