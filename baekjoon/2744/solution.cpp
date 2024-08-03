#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string s; cin >> s;
    for (char &c: s) {
        if (c >= 'a') c += 'A' - 'a';
        else c += 'a' - 'A';
    }
    cout << s << '\n';
}