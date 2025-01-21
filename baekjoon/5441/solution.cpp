#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int s, n, p; cin >> s >> n >> p;
        vector<int> w(s + 1, -1);
        for (int i = 1; i <= s; i++) {
            int cnt = 0, fst = 0;
            for (int j = 1; j <= min(i, n); j++) {
                if (w[i - j] < 0 || w[i - j] == j) {
                    cnt++;
                    if (!fst) fst = j;
                }
            }
            if (cnt > 1) w[i] = 0;
            else if (cnt == 1) w[i] = fst;
        }
        if (w[s] < 0 || w[s] == p) {
            cout << 0 << '\n';
        } else {
            for (int i = 1; i <= n; i++) {
                if (i == p) continue;
                if (w[s - i] < 0 || w[s - i] == i) {
                    cout << i << '\n';
                    break;
                }
            }
        }
    }
}