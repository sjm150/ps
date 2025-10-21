#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        bool used[26] = {};
        int sum = 'A' * 26 + 26 * 25 / 2;
        string s;
        cin >> s;
        for (char c: s) {
            if (!used[c - 'A']) {
                used[c - 'A'] = true;
                sum -= c;
            }
        }
        cout << sum << '\n';
    }
}