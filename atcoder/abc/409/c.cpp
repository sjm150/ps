#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int n, l;
    cin >> n >> l;
    vector<int> d(n);
    d[0] = 0;
    for (int i = 1; i < n; i++) cin >> d[i];

    map<int, int> cnt;
    int p = 0;
    for (int d: d) {
        p = (p + d) % l;
        cnt[p]++;
    }

    auto solve = [&]() {
        if (l % 3) return 0ll;
        ll ans = 0;
        for (auto [p, c]: cnt) {
            int c1 = cnt[(p + l / 3) % l], c2 = cnt[(p + l * 2 / 3) % l];
            ans += ll(c) * c1 * c2;
        }
        return ans / 3;
    };

    cout << solve() << '\n';
}