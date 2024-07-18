#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k, t; cin >> n >> m >> k >> t;
    vector<int> cnt(n + 1, 0);
    while (m--) {
        int a, b; cin >> a >> b;
        cnt[a - 1]++;
        cnt[b - 1]--;
    }
    for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
    cnt.pop_back();

    vector<int> mx(k + 1, 0), v(t + 1, 0);
    auto app = [&]() {
        auto nmx = mx;
        for (int i = 1; i <= t; i++) v[i] += v[i - 1];
        for (int i = 1; i <= t; i++) {
            if (!v[i]) continue;
            for (int j = i; j <= k; j++) nmx[j] = max(nmx[j], mx[j - i] + v[i]);
        }
        swap(mx, nmx);
    };

    int bse = 0;
    bool drt = false;
    for (int c: cnt) {
        if (c < t) {
            v[t - c]++;
            drt = true;
        } else {
            if (drt) {
                app();
                fill(v.begin(), v.end(), 0);
                drt = false;
            }
            bse++;
        }
    }
    if (drt) app();

    cout << bse + *max_element(mx.begin(), mx.end()) << '\n';
}