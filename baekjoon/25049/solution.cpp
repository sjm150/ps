#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int n;
    cin >> n;
    vector<int> p(n);
    for (int &p: p) cin >> p;

    vector<ll> pref(n), suff(n);
    pref[0] = p[0];
    for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + p[i];
    suff[n - 1] = p[n - 1];
    for (int i = n - 2; i >= 0; i--) suff[i] = suff[i + 1] + p[i];

    vector<ll> pmx(n), smx(n);
    ll mn = min(0ll, pref[0]);
    pmx[0] = max(0ll, pref[0]);
    for (int i = 1; i < n; i++) {
        mn = min(mn, pref[i]);
        pmx[i] = max(pmx[i - 1], pref[i] - mn);
    }
    mn = min(0ll, suff[n - 1]);
    smx[n - 1] = max(0ll, suff[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        mn = min(mn, suff[i]);
        smx[i] = max(smx[i + 1], suff[i] - mn);
    }

    ll mx = 0;
    for (int i = 0; i < n - 1; i++) mx = max(mx, pmx[i] + smx[i + 1]);
    cout << accumulate(p.begin(), p.end(), 0ll) + mx << '\n';
}