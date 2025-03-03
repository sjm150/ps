#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int v, e; cin >> v >> e;
        cout << e - v + 2 << '\n';
    }
}