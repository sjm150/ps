#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<pair<int, int>> mov;
    while (n--) {
        int s, e; cin >> s >> e;
        if (s > e) mov.emplace_back(e, s);
    }
    sort(mov.begin(), mov.end());

    long long dst = m;
    int mine = -1, maxs = -1;
    for (auto &[e, s]: mov) {
        if (e <= maxs) {
            maxs = max(maxs, s);
        } else {
            dst += 2 * (maxs - mine);
            maxs = s;
            mine = e;
        }
    }
    dst += 2 * (maxs - mine);

    cout << dst << '\n';
}