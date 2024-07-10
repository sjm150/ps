#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string t = " ";
    for (int i = 0; i < 26; i++) t += i + 'A';
    t += "',-.?";

    string s;
    getline(cin, s);
    long long cur = 0;
    int len = 0;
    while (s[0] != '#') {
        if (s[0] == '*') {
            if (len) {
                cout << t[cur << (5 - len)];
                cur = len = 0;
            }
            cout << '\n';
        } else {
            int cnt = 0;
            for (char c: s) {
                if (c == ' ') {
                    cnt++;
                } else if (cnt) {
                    cur = cur * 2 + (cnt % 2 == 0);
                    cnt = 0;
                    len++;
                    if (len == 5) {
                        cout << t[cur];
                        cur = len = 0;
                    }
                }
            }
            if (cnt) {
                cur = cur * 2 + (cnt % 2 == 0);
                len++;
                if (len == 5) {
                    cout << t[cur];
                    cur = len = 0;
                }
            }
        }
        getline(cin, s);
    }
}