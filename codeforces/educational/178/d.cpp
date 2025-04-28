#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const int mx = 1e7;
    vector<bool> isp(mx, true);
    vector<int> p;
    for (ll i = 2; i < mx; i++) {
        if (!isp[i]) continue;
        p.push_back(i);
        for (ll j = i * i; j < mx; j += i) isp[j] = false;
    }
    int psz = p.size();
    vector<ll> psum(psz);
    psum[0] = p[0];
    for (int i = 1; i < psz; i++) psum[i] = psum[i - 1] + p[i];

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        sort(a.begin(), a.end(), greater<int>());

        vector<ll> asum(n);
        asum[0] = a[0];
        for (int i = 1; i < n; i++) asum[i] = asum[i - 1] + a[i];

        int ans = 0;
        while (ans < n - 1 && asum[n - 1 - ans] < psum[n - 1 - ans]) ans++;
        cout << ans << '\n';
    }
}