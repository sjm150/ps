#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int n, s;
    ll l;
    cin >> n >> s >> l;
    vector<int> a(n - 1);
    for (int &a: a) cin >> a;
    s--;
    vector<ll> d(n, 0);
    for (int i = 0; i < n - 1; i++) d[i + 1] = d[i] + a[i];

    vector<ll> ld, rd;
    for (int i = s - 1; i >= 0; i--) ld.push_back(d[s] - d[i]);
    for (int i = s + 1; i < n; i++) rd.push_back(d[i] - d[s]);

    int lmx = upper_bound(ld.begin(), ld.end(), l) - ld.begin() - 1, rmx = upper_bound(rd.begin(), rd.end(), l) - rd.begin() - 1;
    int ans = 2 + max(lmx, rmx);
    for (int li = lmx, ri = 0; ri < rd.size(); ri++) {
        while (li >= 0 && ld[li] + rd[ri] * 2 > l) li--;
        if (li < 0) break;
        ans = max(ans, 3 + li + ri);
    }
    for (int li = 0, ri = rmx; li < ld.size(); li++) {
        while (ri >= 0 && ld[li] * 2 + rd[ri] > l) ri--;
        if (ri < 0) break;
        ans = max(ans, 3 + li + ri);
    }

    cout << ans << '\n';
}