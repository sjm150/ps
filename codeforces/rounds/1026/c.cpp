#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> d(n), l(n), r(n);
        for (int &d: d) cin >> d;
        for (int i = 0; i < n; i++) cin >> l[i] >> r[i];

        auto solve = [&]() {
            int h = 0;
            vector<int> idx;
            for (int i = 0; i < n; i++) {
                if (d[i] >= 0) h += d[i];
                else idx.push_back(i);
    
                int sz = idx.size();
                int z = max(0, h + sz - r[i]), o = max(0, l[i] - h);
                if (z + o > sz) return false;

                while (z--) {
                    d[idx.back()] = 0;
                    idx.pop_back();
                }
                while (o--) {
                    d[idx.back()] = 1;
                    h++;
                    idx.pop_back();
                }
            }
            while (!idx.empty()) {
                d[idx.back()] = 0;
                idx.pop_back();
            }
            return true;
        };

        if (solve()) {
            for (int d: d) cout << d << ' ';
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}