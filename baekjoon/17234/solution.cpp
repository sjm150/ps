#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef tuple<int, int, int> ti;
    int n, a, b;
    cin >> n >> a >> b;
    map<ti, int> cnt;
    queue<ti> q;
    auto ins = [&](int x, int y, int z, int c) {
        auto t = make_tuple(x, y, z);
        auto it = cnt.find(t);
        if (it == cnt.end()) {
            cnt[t] = c;
            q.emplace(x, y, z);
        }
    };
    ins(0, 0, 0, 0);
    while (!q.empty()) {
        auto [x, y, z] = q.front();
        q.pop();
        if (x >= n) continue;
        int c = cnt[make_tuple(x, y, z)];
        ins(x + a, y, z, c + 1);
        ins(x + b, y, z + 1, c + 1);
        if ((y + 1) * 10 <= c + 1 && x * 2 < n + a) ins(x * 2, y + 1, z, c + 1);
    }
    int ans = n;
    for (auto it = cnt.lower_bound(make_tuple(n, 0, 0)); it != cnt.end(); it++) ans = min(ans, it->second);
    cout << ans << '\n';
}