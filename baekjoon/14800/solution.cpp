#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef pair<int, int> pi;
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n, p;
        cin >> n >> p;
        vector<int> r(n);
        for (int &r: r) cin >> r;
        vector<vector<pi>> se(n, vector<pi>());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < p; j++) {
                int q;
                cin >> q;
                int s = q * 100 / (r[i] * 110);
                while (q * 100 > 110 * r[i] * s) s++;
                int e = q * 100 / (r[i] * 90);
                if (s <= e) se[i].emplace_back(s, e);
            }
            sort(se[i].begin(), se[i].end());
        }

        vector<int> idx(n, 0), seq(n);
        auto get = [&](int i) { return se[i][idx[i]]; };
        iota(seq.begin(), seq.end(), 0);

        int ans = 0;
        for (;;) {
            if (find_if(seq.begin(), seq.end(), [&](int i) { return idx[i] == int(se[i].size()); }) != seq.end()) break;
            int l = get(*max_element(seq.begin(), seq.end(), [&](int i, int j) { return get(i).first < get(j).first; })).first;
            int r = get(*min_element(seq.begin(), seq.end(), [&](int i, int j) { return get(i).second < get(j).second; })).second;
            if (l > r) {
                idx[*min_element(seq.begin(), seq.end(), [&](int i, int j) { return get(i).first < get(j).first; })]++;
            } else {
                ans++;
                for (int &idx: idx) idx++;
            }
        }

        cout << "Case #" << tc << ": " << ans << '\n';
    }
}