#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<bool> used(10, false);
    for (char c: s) {
        if (c == 'L') {
            for (int i = 0; i < 10; i++) {
                if (!used[i]) {
                    used[i] = true;
                    break;
                }
            }
        } else if (c == 'R') {
            for (int i = 9; i >= 0; i--) {
                if (!used[i]) {
                    used[i] = true;
                    break;
                }
            }
        } else {
            used[c - '0'] = false;
        }
    }
    for (int i = 0; i < 10; i++) cout << (used[i] ? 1 : 0);
    cout << '\n';
}