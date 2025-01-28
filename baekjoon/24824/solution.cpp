#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, s; cin >> n >> s;
    vector<int> h(n), b(s);
    for (int &h: h) cin >> h;
    for (int &b: b) cin >> b;

    vector<set<int>> ss(s);
    for (int i = 0; i < s; i++) {
        for (int bm = 0; bm < (1 << n); bm++) {
            long long sum = 0;
            for (int j = bm; j; j &= j - 1) sum += h[__builtin_ctz(j)];
            if (sum == b[i]) ss[i].insert(bm);
        }
    }

    vector<map<int, int>> used(s);
    for (int ss: ss[0]) used[0].emplace(ss, ss);
    for (int i = 1; i < s; i++) {
        for (auto [p, u]: used[i - 1]) {
            for (int ss: ss[i]) {
                if (!(p & ss)) used[i].emplace(p | ss, ss);
            }
        }
    }

    function<void(int, int)> prnt = [&](int idx, int bm) {
        int cur = used[idx].find(bm)->second;
        if (idx > 0) prnt(idx - 1, bm - cur);
        vector<int> ans;
        for (int i = cur; i; i &= i - 1) ans.push_back(__builtin_ctz(i) + 1);
        cout << ans.size() << ' ';
        for (int a: ans) cout << a << ' ';
        cout << '\n';
    };
    if (!used[s - 1].empty()) prnt(s - 1, used[s - 1].begin()->first);
    else cout << -1 << '\n';
}