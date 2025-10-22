#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const string x = "CAMBRIDGE";
    string s;
    cin >> s;
    for (char c: s) {
        if (find(x.begin(), x.end(), c) == x.end()) cout << c;
    }
    cout << '\n';
}