#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const int mod = 1e9 + 7;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    sort(a.begin(), a.end());

    vector<int> pre(n);
    pre[0] = -1;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] == a[i]) pre[i] = pre[i - 1];
        else pre[i] = i - 1;
    }

    vector<ll> pref(n), pa(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++) pref[i] = (pref[i - 1] + a[i]) % mod;
    pa[0] = 0;
    for (int i = 1; i < n; i++) pa[i] = (pa[i - 1] + (pre[i] < 0 ? 0 : pref[pre[i]]) * a[i]) % mod;

    ll ans = 0;
    for (int i = 1; i < n; i++) ans = (ans + (pre[i] < 0 ? 0 : pa[pre[i]]) * a[i]) % mod;
    cout << ans << '\n';
}