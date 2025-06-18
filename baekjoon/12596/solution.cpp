#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int g;
        cin >> g;
        map<int, int> cnt;
        while (g--) {
            int c;
            cin >> c;
            cnt[c]++;
        }
        for (auto [x, c]: cnt) {
            if (c == 1) {
                cout << "Case #" << tc << ": " << x << '\n';
                break;
            }
        }
    }
}