#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    ll m, k; cin >> m >> k;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    ll l = 0, r = m + 1;
    while (l < r) {
        ll x = (l + r) / 2;
        int s = 0, e = 0;
        ll sum = a[0], cnt = 0;
        while (e < n) {
            if (s <= e && ((x == 0 && m <= sum) || (x && (m - sum + x - 1) / x <= e - s + 1))) {
                cnt += n - e;
                sum -= a[s++];
            } else {
                e++;
                if (e == n) break;
                sum += a[e];
            }
        }
        if (cnt < k) l = x + 1;
        else r = x;
    }
    cout << l << '\n';
}