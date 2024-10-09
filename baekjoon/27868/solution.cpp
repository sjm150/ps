#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, s; cin >> n >> s;
    while (n--) cin >> s;
    string c; cin >> c;
    reverse(c.begin(), c.end());
    cout << c << '\n';
}