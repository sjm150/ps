#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s;
    int st = 0;
    for (char c: s) {
        if (st == 1) {
            if (c == 'S') st = 2;
            else if (c == 'P') st = 1;
            else st = 0;
        } else if (st == 2) {
            if (c == '4' || c == '5') continue;
            else if (c == 'P') st = 1;
            else st = 0;
        } else {
            if (c == 'P') st = 1;
        }
        cout << c;
    }
    cout << '\n';
}