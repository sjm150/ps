#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef tuple<int, int, int> ti;
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ti> xyi(n);
        for (int i = 0; i < n; i++) {
            auto &[x, y, ii] = xyi[i];
            cin >> x >> y;
            ii = i;
        }
        sort(xyi.begin(), xyi.end());
        auto cmp = [](ti &a, ti &b) { return get<1>(a) < get<1>(b); };
        sort(xyi.begin(), xyi.begin() + n / 2, cmp);
        sort(xyi.begin() + n / 2, xyi.end(), cmp);
        for (int i = 0; i < n / 2; i++) {
            cout << get<2>(xyi[i]) + 1 << ' ' << get<2>(xyi[n - 1 - i]) + 1 << '\n';
        }
    }
}