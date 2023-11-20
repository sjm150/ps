#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;

        int cnt = 0;
        for (char c: s) {
            if (c == 'B') cnt++;
        }
        if (cnt == k) {
            cout << 0 << '\n';
            continue;
        }

        cnt = 0;
        cout << 1 << '\n';
        for (int i = s.size() - 1; i >= 0; i--) {
            if (cnt == k) {
                cout << i + 1 << " A\n";
                break;
            } else if (i + 1 + cnt == k) {
                cout << i + 1 << " B\n";
                break;
            }
            if (s[i] == 'B') cnt++;
        }
    }
}