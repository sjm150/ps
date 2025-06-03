#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        int cb = 0, ba = 0, ca = 0, bc = 0, cba = 0, bca = 0;
        while (q--) {
            char x, y;
            cin >> x >> y;
            if (x == 'c' && y == 'b') {
                cb++;
            } else if (x == 'b' && y == 'a') {
                ba++;
                if (cb && ba) {
                    cb--, ba--;
                    cba++;
                }
            } else if (x == 'c' && y == 'a') {
                ca++;
                if (bc && ca) {
                    bc--, ca--;
                    bca++;
                }
            } else if (x == 'b' && y == 'c') {
                bc++;
            }
        }

        for (char &c: s) {
            if (c == 'b') {
                if (ba) {
                    ba--;
                    c = 'a';
                } else if (cba) {
                    cba--;
                    cb++;
                    c = 'a';
                } else if (bca) {
                    bca--;
                    c = 'a';
                }
            } else if (c == 'c') {
                if (ca) {
                    ca--;
                    c = 'a';
                } else if (bca) {
                    bca--;
                    bc++;
                    c = 'a';
                } else if (cba) {
                    cba--;
                    c = 'a';
                } else if (cb) {
                    cb--;
                    c = 'b';
                }
            }
        }
        cout << s << '\n';
    }
}