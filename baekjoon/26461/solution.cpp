#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, l; cin >> n >> l;
    vector<tuple<int, int, int>> xgr(n);
    for (auto &[x, g, r]: xgr) cin >> x >> g >> r;
    sort(xgr.begin(), xgr.end());
    long long t = 0;
    int p = 0;
    for (auto [x, g, r]: xgr) {
        t += x - p;
        p = x;
        int rem = t % (g + r);
        if (rem >= g) t += g + r - rem;
    }
    cout << t + l - p << '\n';
}