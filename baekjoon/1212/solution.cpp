#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    const string v[] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    bool ok = false;
    for (char c: s) {
        for (char p: v[c - '0']) {
            if (ok) {
                cout << p;
            } else {
                if (p == '1') {
                    ok = true;
                    cout << p;
                }
            }
        }
    }
    if (!ok) cout << 0;
    cout << '\n';
}