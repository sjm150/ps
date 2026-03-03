#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int mod = 998244353;
    typedef pair<int, int> pi;
    int n;
    cin >> n;
    vector<pi> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i].first >> y[i].first >> x[i].second >> y[i].second;

    auto calc = [&](vector<pi> &a) {
        vector<int> s, p(n + 1);
        for (auto [_, a]: a) s.push_back(a);
        sort(s.begin(), s.end());
        p[0] = 0;
        for (int i = 0; i < n; i++) p[i + 1] = (p[i] + s[i]) % mod;
        int res = 0;
        for (auto [a, _]: a) {
            int idx = lower_bound(s.begin(), s.end(), a) - s.begin();
            res = (res + (long long)(idx) * a - p[idx] + mod) % mod;
        }
        return res;
    };

    cout << (calc(x) + calc(y)) % mod << '\n';
}