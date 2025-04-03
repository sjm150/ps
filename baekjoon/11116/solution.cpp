#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int m; cin >> m;
        multiset<int> l, r;
        for (int i = 0; i < m; i++) {
            int x; cin >> x;
            l.insert(x);
        }
        for (int i = 0; i < m; i++) {
            int x; cin >> x;
            r.insert(x);
        }
        int ans = 0;
        m /= 2;
        while (m--) {
            int lf = *l.begin(), rf = *r.begin();
            if (lf < rf) {
                ans++;
                l.erase(l.find(lf));
                l.erase(l.find(lf + 500));
                r.erase(r.find(lf + 1000));
                r.erase(r.find(lf + 1500));
            } else {
                l.erase(l.find(rf + 1000));
                l.erase(l.find(rf + 1500));
                r.erase(r.find(rf));
                r.erase(r.find(rf + 500));
            }
        }
        cout << ans << '\n';
    }
}