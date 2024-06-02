#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        sort(a.begin(), a.end());

        ll ans = 0;
        for (int i = k; i > m; i -= m) ans += ll(i - m) * m;
        for (int a: a) {
            ans += ll(min(m, k)) * a;
            k -= m;
            if (k <= 0) break;
        }

        cout << ans << '\n';
    }
}