#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<int> p(n);
        for (int &p: p) {
            cin >> p;
            p--;
        }
        string s; cin >> s;

        vector<bool> chk(n - 1, false);
        int x = 0;
        for (int i = 0; i < n - 1; i++) {
            x = max(x, p[i]);
            if (i < x) chk[i] = true;
        }
        x = n - 1;
        for (int i = n - 1; i; i--) {
            x = min(x, p[i]);
            if (x < i) chk[i - 1] = true;
        }

        int cnt = 0;
        auto blk = [&](int i) { return chk[i] && s[i] == 'L' && s[i + 1] == 'R'; };
        for (int i = 0; i < n - 1; i++) {
            if (blk(i)) cnt++;
        }
        while (q--) {
            int i; cin >> i;
            i--;
            if (blk(i - 1)) cnt--;
            if (blk(i)) cnt--;
            s[i] = 'L' + 'R' - s[i];
            if (blk(i - 1)) cnt++;
            if (blk(i)) cnt++;
            cout << (cnt ? "NO\n" : "YES\n");
        }
    }
}