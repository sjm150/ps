#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int nm[2]; cin >> nm[0] >> nm[1];
        int sz = nm[0] + nm[1] + 1;
        vector<vector<int>> ab(sz, vector<int>(2));
        for (auto &ab: ab) cin >> ab[0];
        for (auto &ab: ab) cin >> ab[1];

        vector<int> pst(sz);
        int cnt[] = {0, 0};
        int mis = -1;
        long long val = 0;

        for (int i = 0; i < sz - 1; i++) {
            int p = ab[i][0] < ab[i][1];
            if (cnt[p] == nm[p]) {
                p = 1 - p;
                if (mis < 0) mis = i;
            }
            pst[i] = p;
            cnt[p]++;
            val += ab[i][p];
        }

        for (int i = 0; i < sz - 1; i++) {
            val -= ab[i][pst[i]];
            if (mis >= 0 && i < mis && pst[i] != pst[mis]) cout << val - ab[mis][pst[mis]] + ab[mis][1 - pst[mis]] + ab[sz - 1][pst[mis]] << ' ';
            else cout << val + ab[sz - 1][pst[i]] << ' ';
            val += ab[i][pst[i]];
        }
        cout << val << '\n';
    }
}