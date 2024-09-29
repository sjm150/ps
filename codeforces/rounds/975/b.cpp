#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<int> x(n);
        for (int &x: x) cin >> x;
        map<ll, ll> cnt;
        for (int i = 0; i < n; i++) cnt[ll(i + 1) * (n - i) - 1]++;
        for (int i = 1; i < n; i++) cnt[ll(n - i) * i] += x[i] - x[i - 1] - 1;
        while (q--) {
            ll k; cin >> k;
            cout << cnt[k] << ' ';
        }
        cout << '\n';
    }
}