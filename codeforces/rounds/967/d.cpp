#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        map<int, int> ar;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ar[a[i]] = i;
        }
        vector<pair<int, int>> ra;
        for (auto &[a, r]: ar) ra.emplace_back(r, a);
        sort(ra.begin(), ra.end());
        int sz = ra.size();

        set<int> used, cand;
        map<int, queue<int>> q;
        auto add = [&](int i) {
            if (used.find(a[i]) != used.end()) return;
            if (q[a[i]].empty()) cand.insert(a[i]);
            q[a[i]].push(i);
        };
        auto del = [&](int i) {
            if (used.find(a[i]) != used.end()) return;
            q[a[i]].pop();
            if (q[a[i]].empty()) cand.erase(a[i]);
        };

        vector<int> ans;
        int l = 0, idx = 0;
        for (int i = 0; i <= ra[0].first; i++) add(i);
        while (used.size() < sz) {
            while (idx < sz && used.find(ra[idx].second) != used.end()) {
                idx++;
                if (idx == sz) break;
                for (int i = ra[idx - 1].first + 1; i <= ra[idx].first; i++) add(i);
            }
            int x = (used.size() % 2 ? *cand.begin() : *prev(cand.end()));
            ans.push_back(x);
            int nl = q[x].front();
            while (l <= nl) del(l++);
            used.insert(x);
            cand.erase(x);
        }

        cout << sz << '\n';
        for (int a: ans) cout << a << ' ';
        cout << '\n';
    }
}