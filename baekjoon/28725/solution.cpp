#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> b(n);
    for (int &b: b) cin >> b;

    auto tot = [&](ll m) {
        ll cnt = 0, t = 1;
        int len = 0;
        for (; t <= m; t *= n, len++) cnt += len * (n - 1) * t / n;
        cnt += (m - t / n + 1) * len;
        return cnt;
    };

    ll sum = accumulate(b.begin(), b.end(), 0ll);
    ll l = 1, r = sum + 1;
    while (l < r) {
        ll m = (l + r) / 2;
        ll cnt = tot(m);
        if (cnt < sum) l = m + 1;
        else if (cnt > sum) r = m;
        else break;
    }

    ll m = (l + r) / 2;
    vector<ll> cnt(n, 0);
    ll t = 1;
    int len = 0;
    for (; t <= m; t *= n, len++) {
        int c = m / t % n;
        for (int i = 1; i < n; i++) cnt[i] += len * t / n * c;
        for (int i = 1; i < c; i++) cnt[i] += t;
        cnt[c] += m % t + 1;
    }
    cnt[0] = tot(m) - accumulate(cnt.begin() + 1, cnt.end(), 0ll);

    for (int i = 0; i < n; i++) {
        if (cnt[i] == b[i]) continue;
        cout << -1 << '\n';
        return 0;
    }
    cout << m << '\n';
}