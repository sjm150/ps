#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool ok = false;
        int cur = 0;
        s.pop_back();
        for (char c: s) {
            cur += (c == '(' ? 1 : -1);
            if (cur <= 0) {
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}