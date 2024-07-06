#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        string w; cin >> w;
        int k; cin >> k;
        int n = w.size();
        vector<vector<int>> idcs(26);
        for (int i = 0; i < n; i++) idcs[w[i] - 'a'].push_back(i);
        int mnl = n + 1, mxl = -1;
        for (auto &idx: idcs) {
            for (int i = 0; i + k - 1 < idx.size(); i++) {
                int l = idx[i + k - 1] - idx[i] + 1;
                mnl = min(mnl, l);
                mxl = max(mxl, l);
            }
        }
        if (mnl <= n && mxl >= 0) cout << mnl << ' ' << mxl << '\n';
        else cout << -1 << '\n';
    }
}