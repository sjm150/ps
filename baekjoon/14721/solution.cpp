#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<pair<int, int>> xy(n);
    for (auto &[x, y]: xy) cin >> x >> y;
    ll mnr = 1e18;
    int mna = -1, mnb = -1;
    for (int a = 1; a <= 100; a++) {
        for (int b = 1; b <= 100; b++) {
            ll r = 0;
            for (auto [x, y]: xy) {
                int t = a * x + b;
                r += ll(y - t) * (y - t);
            }
            if (mnr > r) {
                mnr = r;
                mna = a, mnb = b;
            }
        }
    }
    cout << mna << ' ' << mnb << '\n';
}