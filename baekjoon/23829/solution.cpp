#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, q; cin >> n >> q;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p.begin(), p.end());

    vector<ll> sum(n + 1);
    sum[0] = 0;
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + p[i - 1];

    while (q--) {
        int x; cin >> x;
        int i = upper_bound(p.begin(), p.end(), x) - p.begin();
        cout << sum[n] - 2 * sum[i] + sum[0] + ll(2 * i - n) * x << '\n';
    }
}