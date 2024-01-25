#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

ll exp(ll x, int e) {
    ll ret = 1;
    while (e) {
        if (e & 1) ret = ret * x % mod;
        x = x * x % mod;
        e >>= 1;
    }
    return ret;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int r, c, k; cin >> r >> c >> k;
    map<int, set<int>> brk;
    while (k--) {
        int x, y; cin >> x >> y;
        brk[x - 1].insert(y - 1);
    }

    ll cnt = (r - ll(brk.size())) * (c / 2);
    ll knd = 1;
    if (c & 1) knd = exp(c / 2 + 1, r - ll(brk.size()));
    for (auto &[i, brk]: brk) {
        int pre = -1;
        for (int cur: brk) {
            int d = cur - pre - 1;
            if (d >= 2) {
                int t = d / 2;
                cnt += t;
                if (d & 1) knd = knd * (t + 1) % mod;
            }
            pre = cur;
        }
        int d = c - pre - 1;
        if (d >= 2) {
            int t = d / 2;
            cnt += t;
            if (d & 1) knd = knd * (t + 1) % mod;
        }
    }

    cout << cnt << ' ' << knd << '\n';
}