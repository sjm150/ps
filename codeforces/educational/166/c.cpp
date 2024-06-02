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

        vector<int> pst(sz), mis;
        pst[0] = ab[0][0] < ab[0][1];
        long long val = 0;
        int cnt[2] = {0, 0}, lst = 0;

        for (int i = 1; i < sz; i++) {
            if (ab[i][0] > ab[i][1]) {
                if (cnt[0] < nm[0]) {
                    pst[i] = 0;
                    val += ab[i][0];
                    cnt[0]++;
                } else {
                    pst[i] = 1;
                    val += ab[i][1];
                    if (pst[0] == 1) mis.push_back(i);
                }
            } else {
                if (cnt[1] < nm[1]) {
                    pst[i] = 1;
                    val += ab[i][1];
                    cnt[1]++;
                } else {
                    pst[i] = 0;
                    val += ab[i][0];
                    if (pst[0] == 0) mis.push_back(i);
                }
            }
            if (pst[0] == pst[i]) lst = i;
        }

        cout << val << ' ';
        val += ab[0][pst[0]];
        for (int i = 1; i < sz; i++) {
            val -= ab[i][pst[i]];
            if (pst[0] == pst[i]) {
                cout << val << ' ';
            } else {
                auto it = upper_bound(mis.begin(), mis.end(), i);
                if (it != mis.end()) cout << val - ab[*it][pst[0]] + ab[*it][pst[i]] << ' ';
                else cout << val - ab[lst][pst[0]] + ab[lst][pst[i]] << ' ';
            }
            val += ab[i][pst[i]];
        }
        cout << '\n';
    }
}