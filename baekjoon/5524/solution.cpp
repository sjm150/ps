#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        for (char &c: s) {
            if ('A' <= c && c <= 'Z') c += 'a' - 'A';
        }
        cout << s << '\n';
    }
}