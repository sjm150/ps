#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> l(n);
    for (int &l: l) cin >> l;
    sort(l.begin(), l.end());
    int k; cin >> k;

    int sz = l[n - 1] + 2;
    vector<vector<ll>> cnt(k, vector<ll>(sz, 0));
    fill(cnt[0].begin(), cnt[0].end(), 1);

    ll ans = 1;
    for (int i = 0; i < k; i++) ans = ans * (n - i) / (i + 1);
    for (int l: l) {
        ans -= cnt[k - 1][l];
        for (int i = k - 1; i; i--) {
            for (int j = 0; j < sz; j++) cnt[i][min(sz - 1, j + l)] += cnt[i - 1][j];
        }
    }
    cout << ans << '\n';
}