#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        int cnt = 0;
        int lidx = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cnt++;
                lidx = i;
            }
        }

        if (cnt == 2 && s[lidx - 1] == '1') {
            cout << "NO\n";
            continue;
        }

        cout << (cnt & 1 ? "NO": "YES") << '\n';
    }
}