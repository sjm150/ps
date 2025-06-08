#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    const int mod = 1e9 + 7;
    int n;
    cin >> n;
    vector<int> h(n);
    for (int &h: h) cin >> h;

    auto solve = [&]() {
        if (h[0] > 0 || h[n - 1] > 0) return 0;
        h[0] = h[n - 1] = 0;

        int sz = n / 2;
        vector<int> cnt(sz + 1, 0);
        cnt[0] = 1;
        for (int i = 1; i < n; i++) {
            if (h[i] < 0) {
                auto nc = cnt;
                for (int j = 0; j <= sz; j++) {
                    if (j > 0) nc[j] = (nc[j] + cnt[j - 1]) % mod;
                    if (j < sz) nc[j] = (nc[j] + cnt[j + 1]) % mod;
                }
                swap(cnt, nc);
            } else {
                int c = cnt[h[i]];
                if (h[i] > 0) c = (c + cnt[h[i] - 1]) % mod;
                if (h[i] < sz) c = (c + cnt[h[i] + 1]) % mod;
                fill(cnt.begin(), cnt.end(), 0);
                cnt[h[i]] = c;
            }
        }

        return cnt[0];
    };

    cout << solve() << '\n';
}