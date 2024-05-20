#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = 1e18;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int m, x; cin >> m >> x;
        vector<pair<int, int>> ch(m);
        int sumh = 0;
        for (auto &[c, h]: ch) {
            cin >> c >> h;
            sumh += h;
        }
        vector<ll> cst(sumh + 1, inf);
        cst[0] = 0;
        for (int i = 0; i < m; i++) {
            auto [c, h] = ch[i];
            for (int j = sumh; j >= h; j--) {
                if (cst[j - h] + c <= ll(i) * x) cst[j] = min(cst[j], cst[j - h] + c);
            }
        }
        for (int h = sumh; h >= 0; h--) {
            if (cst[h] < inf) {
                cout << h << '\n';
                break;
            }
        }
    }
}