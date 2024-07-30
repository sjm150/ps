#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        bool poss = true;
        for (int ai: a) {
            if (abs(ai - a[0]) % 2) {
                poss = false;
                break;
            }
        }
        if (!poss) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> x;
        while (x.size() < 40) {
            int mn = *min_element(a.begin(), a.end());
            int mx = *max_element(a.begin(), a.end());
            if (mn == mx) {
                x.push_back(mn);
                break;
            }
            if (mx == 2) {
                x.push_back(1);
                x.push_back(1);
                break;
            }
            int m = (mx - mn) / 4 * 2 + mn;
            for (int &a: a) a = abs(a - m);
            x.push_back(m);
        }

        cout << x.size() << '\n';
        for (int x: x) cout << x << ' ';
        cout << '\n';
    }
}