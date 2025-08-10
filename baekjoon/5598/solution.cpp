#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    for (char &c: s) c = (c - 'A' + 23) % 26 + 'A';
    cout << s << '\n';
}