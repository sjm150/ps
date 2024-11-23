#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, a, b; cin >> n >> a >> b;
        string s; cin >> s;
        bool ok = false;
        int x = 0, y = 0;
        for (int i = 0; i < 100; i++) {
            for (char c: s) {
                if (c == 'N') y++;
                else if (c == 'E') x++;
                else if (c == 'S') y--;
                else x--;
                if (x == a && y == b) {
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}