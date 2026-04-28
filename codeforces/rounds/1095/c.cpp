#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        sort(a.begin(), a.end());
        int l = 0, r = a.back() + 1;
        while (l < r) {
            int m = (l + r) / 2;
            set<int> rem;
            for (int i = 0; i <= m; i++) rem.insert(i);
            for (int a: a) {
                auto it = rem.find(a);
                if (it != rem.end()) {
                    rem.erase(it);
                } else {
                    it = rem.upper_bound((a - 1) / 2);
                    if (it != rem.begin()) rem.erase(prev(it));
                }
            }
            if (rem.empty()) l = m + 1;
            else r = m;
        }
        cout << r << '\n';
    }
}