#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int r, g, b; cin >> r >> g >> b;
    string c; cin >> c;
    if (c == "Red") cout << min(g, b) << '\n';
    else if (c == "Blue") cout << min(r, g) << '\n';
    else cout << min(r, b) << '\n';
}