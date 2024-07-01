#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string a, b; cin >> a >> b;
    int c; cin >> c;
    cout << stoi(a) + stoi(b) - c << '\n';
    cout << stoi(a + b) - c << '\n';
}