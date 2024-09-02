#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> a(n);
    for (ll &a: a) cin >> a;

    vector<pli> ord(n);
    for (int i = 0; i < n; i++) ord[i] = {a[i], i};
    sort(ord.begin(), ord.end());
    vector<int> tar(n);
    for (int i = 0; i < n; i++) tar[ord[i].second] = i;

    ll ans = 0;
    int l = 0;
    while (l < n) {
        int r = l;
        for (int i = l; i <= r; i++) r = max(r, tar[i]);
        sort(a.begin() + l, a.begin() + r + 1);
        for (int i = l; i < r; i++) ans = max(ans, a[i + 1] - a[i]);
        l = r + 1;
    }
    cout << ans << '\n';
}