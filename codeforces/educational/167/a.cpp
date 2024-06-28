#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    while (n--) {
        int x, y; cin >> x >> y;
        cout << (y >= -1 ? "YES\n" : "NO\n");
    }
}