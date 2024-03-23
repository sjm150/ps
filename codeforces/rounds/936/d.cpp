#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        vector<vector<int>> a(31);
        a[30].resize(n);
        for (int &a: a[30]) cin >> a;

        vector<int> ors(31, 0);
        for (int a: a[30]) ors[30] |= a;
        int b = 1 << 29;
        int ans = -1;

        for (int i = 29; i >= 0; i--, b >>= 1) {
            if (ors[i + 1] <= x) {
                ans = max(ans, int(a[i + 1].size()));
                break;
            }
            if ((ors[i + 1] & b) == 0) {
                swap(a[i], a[i + 1]);
                swap(ors[i], ors[i + 1]);
                continue;
            }

            vector<int> pos;
            for (int j = 0; j < a[i + 1].size(); j++) {
                if (a[i + 1][j] & b) pos.push_back(j);
            }
            if (pos.size() & 1) {
                swap(a[i], a[i + 1]);
                swap(ors[i], ors[i + 1]);
                continue;
            }

            int idx = 0;
            for (int j = 0; j < pos.size(); j += 2) {
                while (idx < pos[j]) a[i].push_back(a[i + 1][idx++]);
                int xsum = 0;
                for (int k = pos[j]; k <= pos[j + 1]; k++) xsum ^= a[i + 1][k];
                a[i].push_back(xsum);
                idx = pos[j + 1] + 1;
            }
            while (idx < a[i + 1].size()) a[i].push_back(a[i + 1][idx++]);

            for (int a: a[i]) ors[i] |= a;
            if (ors[i] <= x) {
                ans = max(ans, int(a[i].size()));
                swap(a[i], a[i + 1]);
                swap(ors[i], ors[i + 1]);
            }
        }

        cout << ans << '\n';
    }
}