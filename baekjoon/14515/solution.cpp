#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s; cin >> s;
    int w = 0, b = 0;
    for (char c: s) (c == 'W' ? w : b)++;
    cout << (w == b) << '\n';
}