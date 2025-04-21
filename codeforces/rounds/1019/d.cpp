#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) {
            cin >> a;
            a--;
        }
        int sz = *max_element(a.begin(), a.end()) + 1, neg = -1;
        vector<vector<int>> pos(sz);
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) neg = i;
            else pos[a[i]].push_back(i);
        }

        set<int> rem;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) rem.insert(i);
        int l = 1, r = n;
        auto asgn = [&](int idx, int op) {
            if (op % 2 == 0) ans[idx] = r--;
            else ans[idx] = l++;
            rem.erase(idx);
        };
        for (int p = 0; p < sz; p++) {
            while (!rem.empty() && a[*rem.begin()] == p) asgn(*rem.begin(), p);
            while (!rem.empty() && a[*prev(rem.end())] == p) asgn(*prev(rem.end()), p);
            for (int i: pos[p]) {
                if (ans[i] == 0) asgn(i, p);
            }
        }
        ans[neg] = l;
        assert(l == r);

        for (int a: ans) cout << a << ' ';
        cout << '\n';
    }
}