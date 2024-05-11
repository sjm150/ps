#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        map<int, pair<vector<int>, vector<int>>> m;
        for (int i = 0; i < n; i++) {
            auto it = m.find(a[i] & -4);
            if (it == m.end()) it = m.emplace(a[i] & -4, make_pair(vector<int>(), vector<int>())).first;
            it->second.first.push_back(i);
            it->second.second.push_back(a[i]);
        }

        vector<pair<int, int>> ans;
        for (auto &[k, v]: m) {
            auto &[idx, val] = v;
            sort(val.begin(), val.end());
            for (int i = 0; i < val.size(); i++) ans.emplace_back(idx[i], val[i]);
        }
        sort(ans.begin(), ans.end());

        for (auto [i, v]: ans) cout << v << ' ';
        cout << '\n';
    }
}