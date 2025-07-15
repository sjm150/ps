#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s;
    getline(cin, s);
    for (char &c: s) {
        if ('a' <= c && c <= 'z') c = (c - 'a' + 13) % 26 + 'a';
        else if ('A' <= c && c <= 'Z') c = (c - 'A' + 13) % 26 + 'A';
    }
    cout << s << '\n';
}