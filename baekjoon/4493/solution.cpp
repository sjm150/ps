#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        while (n--) {
            char a, b;
            cin >> a >> b;
            const auto cnv = [](char c) {
                if (c == 'R') return 0;
                else if (c == 'S') return 1;
                else return 2;
            };
            int x = cnv(a), y = cnv(b);
            if ((x + 1) % 3 == y) ans++;
            else if (x == (y + 1) % 3) ans--;
        }
        if (ans > 0) cout << "Player 1\n";
        else if (ans < 0) cout << "Player 2\n";
        else cout << "TIE\n";
    }
}