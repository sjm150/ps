#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<string> s(n);
        for (auto &s: s) cin >> s;
        string narek = "narek";
        vector<int> scr(5, -inf);
        scr[0] = 0;
        for (int i = 1; i <= n; i++) {
            int tot = 0;
            for (char c: s[i - 1]) {
                if (c == 'n' || c == 'a' || c == 'r' || c == 'e' || c == 'k') tot++;
            }
            vector<int> nscr = scr;
            for (int j = 0; j < 5; j++) {
                int k = j, cnt = 0;
                for (char c: s[i - 1]) {
                    if (c == narek[k]) {
                        k++;
                        if (k == 5) {
                            cnt++;
                            k = 0;
                        }
                    }
                }
                nscr[k] = max(nscr[k], scr[j] + 10 * cnt - tot);
            }
            swap(scr, nscr);
        }
        cout << *max_element(scr.begin(), scr.end()) << '\n';
    }
}