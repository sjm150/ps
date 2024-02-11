#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, t; cin >> n >> t;
    vector<int> s(mx + 1, 0), e(mx + 1, 0);
    while (n--) {
        int k; cin >> k;
        while (k--) {
            int si, ei; cin >> si >> ei;
            s[si]++, e[ei]++;
        }
    }

    vector<ll> cnt(mx + 1);
    cnt[0] = 0;
    int cur = 0;
    for (int i = 0; i < mx; i++) {
        cur += s[i] - e[i];
        cnt[i + 1] = cnt[i] + cur;
    }

    ll maxc = -1, maxs = -1;
    for (int i = t; i <= mx; i++) {
        if (maxc < cnt[i] - cnt[i - t]) {
            maxc = cnt[i] - cnt[i - t];
            maxs = i - t;
        }
    }
    cout << maxs << ' ' << maxs + t << '\n';
}