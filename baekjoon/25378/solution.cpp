#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;

    map<int, int> pre;
    pre[0] = 0;
    for (int a: a) {
        map<int, int> cur;
        auto asgn = [&](int k, int v) {
            auto it = cur.find(k);
            if (it == cur.end()) cur[k] = v;
            else it->second = min(it->second, v);
        };
        for (auto [p, v]: pre) {
            asgn(a, v + (p > 0));
            if (p <= a) asgn(a - p, v + 1);
        }
        swap(pre, cur);
    }

    int ans = n;
    for (auto [p, v]: pre) {
        if (p) ans = min(ans, v + 1);
        else ans = min(ans, v);
    }
    cout << ans << '\n';
}