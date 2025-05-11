#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        vector<pair<int, ll>> lc = {{-1, 0}}, rc = {{n, 0}};
        {
            set<int> s;
            for (int i = 1; i <= n; i++) s.insert(i);
            for (int i = 0; i < n; i++) {
                auto it = s.upper_bound(a[i]);
                if (it != s.begin()) {
                    s.erase(prev(it));
                    lc.emplace_back(i, lc.back().second + i);
                }
            }
        }
        {
            set<int> s;
            for (int i = 1; i <= n; i++) s.insert(i);
            for (int i = n - 1; i >= 0; i--) {
                auto it = s.upper_bound(a[i]);
                if (it != s.begin()) {
                    s.erase(prev(it));
                    rc.emplace_back(i, rc.back().second + n - 1 - i);
                }
            }
        }

        for (int i = min(lc.size(), rc.size()) - 1; i >= 0; i--) {
            if (lc[i].first >= rc[i].first) continue;
            cout << i * ll(n - 1) - lc[i].second - rc[i].second << '\n';
            break;
        }
    }
}