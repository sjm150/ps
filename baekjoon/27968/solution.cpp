#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int n, m;
    cin >> n >> m;
    vector<ll> a(m);
    for (ll &a: a) cin >> a;
    for (int i = 1; i < m; i++) a[i] += a[i - 1];
    while (n--) {
        ll b;
        cin >> b;
        int idx = lower_bound(a.begin(), a.end(), b) - a.begin();
        if (idx < m) cout << idx + 1 << '\n';
        else cout << "Go away!\n";
    }
}