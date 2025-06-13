#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    int d = 1, sum = 0;
    for (int i = 0; i < 13; i++) {
        if (s[i] == '*') {
            if (i % 2) d = 7;
        } else {
            sum += (s[i] - '0') * (i % 2 ? 3 : 1);
        }
    }
    cout << (-sum % 10 + 10) * d % 10 << '\n';
}