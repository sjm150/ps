#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s, r; cin >> s >> r;
        int z = 0, o = 0;
        for (char c: s) {
            if (c == '0') z++;
            else o++;
        }
        bool ok = true;
        for (char c: r) {
            if (z && o) {
                if (c == '0') o--;
                else z--;
            } else {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}