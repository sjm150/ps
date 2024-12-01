#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        set<int> p1, p2;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1) p1.insert(i);
            else if (a[i] == 2) p2.insert(i);
        }
        vector<pair<int, int>> ans;
        int sz = p2.size();
        for (int i = n - 1; i >= n - sz; i--) {
            if (a[i] == 1 && !p2.empty()) {
                int p = *p2.begin();
                if (p < i) {
                    swap(a[p], a[i]);
                    p2.erase(p);
                    p1.erase(i);
                    p2.insert(i);
                    p1.insert(p);
                    ans.emplace_back(p + 1, i + 1);
                }
            }
        }
        for (int i = n - 1; i; i--) {
            if (a[i] == 0 && !p1.empty()) {
                int p = *p1.begin();
                if (p < i) {
                    swap(a[p], a[i]);
                    p1.erase(p);
                    p1.insert(i);
                    ans.emplace_back(p + 1, i + 1);
                }
            }
            if (a[i] == 1 && !p2.empty()) {
                int p = *p2.begin();
                if (p < i) {
                    swap(a[p], a[i]);
                    p2.erase(p);
                    p1.erase(i);
                    p2.insert(i);
                    p1.insert(p);
                    ans.emplace_back(p + 1, i + 1);
                }
            }
        }
        cout << ans.size() << '\n';
        for (auto [u, v]: ans) cout << u << ' ' << v << '\n';
    }
}