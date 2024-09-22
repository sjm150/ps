#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int r = 333, c = 999;
    while (r--) {
        int n; cin >> n;
        string s;
        vector<string> out(n, string(n, '0')), res(n - 2);
        auto prnt = [&]() {
            if (!c) return false;
            c--;
            for (auto &o: out) cout << o << '\n';
            cout.flush();
            return true;
        };
        if (n == 3) {
            for (;;) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        out[i][j] = (rng() % 2 ? '1' : '0');
                    }
                }
                if (!prnt()) break;
                cin >> s;
                if (s[0] == 'C') break;
                for (auto &r: res) cin >> r;
            }
        } else {
            out[2][2] = '1';
            if (!prnt()) break;

            cin >> s;
            if (s[0] == 'C') continue;
            for (auto &r: res) cin >> r;

            bool h[3][3] = {};
            int hi = 0, hj = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (res[2 - i][2 - j] == '1') {
                        h[i][j] = true;
                        hi = i;
                        hj = j;
                    }
                }
            }

            for (int i = 0; i < n; i++) fill(out[i].begin(), out[i].end(), '0');
            for (int i = 0; i < n - 2; i++) {
                for (int j = 0; j < n - 2; j++) {
                    int cnt = 0;
                    for (int ii = i; ii < i + 3; ii++) {
                        for (int jj = j; jj < j + 3; jj++) {
                            if (h[ii - i][jj - j] && out[ii][jj] == '1') cnt++;
                        }
                    }
                    if (cnt % 2 == 0) out[i + hi][j + hj] = '1';
                }
            }
            if (!prnt()) break;

            cin >> s;
            assert(s[0] == 'C');
        }
        if (c <= 0) break;
    }
}