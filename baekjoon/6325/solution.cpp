#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (int t = 1;; t++) {
        int n;
        cin >> n;
        if (!n) break;
        bool def[26] = {};
        def[0] = true;
        while (n--) {
            char a, c, b;
            cin >> a >> c >> b;
            def[a - 'a'] = def[b - 'a'];
        }
        cout << "Program #" << t << '\n';
        bool ok = false;
        for (int i = 0; i < 26; i++) {
            if (def[i]) {
                cout << char(i + 'a') << ' ';
                ok = true;
            }
        }
        if (!ok) cout << "none";
        cout << "\n\n";
    }
}