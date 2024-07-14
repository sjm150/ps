#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<ll> l(n), r(n);
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
    ll lsum = accumulate(l.begin(), l.end(), 0ll), rsum = accumulate(r.begin(), r.end(), 0ll);
    if (lsum <= 0 && 0 <= rsum) {
        cout << "Yes\n";
        for (int i = 0; i < n; i++) {
            ll v = min(-lsum, r[i] - l[i]);
            cout << l[i] + v << ' ';
            lsum += v;
        }
        cout << '\n';
    } else {
        cout << "No\n";
    }
}