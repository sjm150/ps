#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s, t; cin >> s >> t;
        bool ext = false, poss = true;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0' && t[i] == '1' && !ext) {
                poss = false;
                break;
            }
            if (s[i] == '1') break;
        }
        cout << (poss ? "YES\n" : "NO\n");
    }
}