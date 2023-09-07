#include <bits/stdc++.h>
using namespace std;

int a[100001];
int xsum[100001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            xsum[i] = xsum[i - 1] ^ a[i];
        }

        string s; cin >> s;
        int totx = 0, zerx = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '0') zerx ^= a[i];
            totx ^= a[i];
        }

        int q; cin >> q;
        while (q--) {
            int cmd; cin >> cmd;
            if (cmd == 1) {
                int l, r; cin >> l >> r;
                zerx ^= xsum[r] ^ xsum[l - 1];
            } else {
                int g; cin >> g;
                if (g == 0) cout << zerx << ' ';
                else cout << (totx ^ zerx) << ' ';
            }
        }
        cout << '\n';
    }
}