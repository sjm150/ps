#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int s, d, k; cin >> s >> d >> k;
        cout << "Case #" << tc << ": ";
        if ((s + 2 * d >= k) && (2 * s + 2 * d > k)) cout << "YES\n";
        else cout << "NO\n";
    }
}