#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef tuple<int, int, int> ti;
    int n, a, b, c, d, e, f;
    cin >> n >> a >> b >> c >> d >> e >> f;
    vector<ti> lhm(n);
    for (auto &[l, h, m]: lhm) cin >> l >> h >> m;
    sort(lhm.begin(), lhm.end(), [](ti &a, ti &b){ return get<1>(a) < get<1>(b); });

    vector<vector<int>> val(b + 1, vector<int>(c + 1));
    fill(val[0].begin(), val[0].end(), a);
    auto eff = [&](int l) {
        if (e > 100) return (l * (100 - e) - 99) / 100;
        else return l * (100 - e) / 100;
    };
    for (int i = 1; i <= b; i++) {
        for (int j = 0; j <= c; j++) val[i][j] = val[i - 1][j] + f;
        for (auto [l, h, m]: lhm) {
            if (i < h) break;
            for (int j = 0; j + m <= c; j++) {
                int v = max(0, val[i - h][j + m] - (j + m > d ? l : eff(l)));
                if (val[i][j] > v) val[i][j] = v;
            }
        }
    }
    cout << *min_element(val[b].begin(), val[b].end()) << '\n';
}