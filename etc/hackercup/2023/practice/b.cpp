#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int r, c, a, b; cin >> r >> c >> a >> b;
        cout << "Case #" << tc << ": ";
        if (r > c) cout << "YES\n";
        else cout << "NO\n";
    }
}