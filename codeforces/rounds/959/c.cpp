#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        vector<ll> suma(n + 1);
        suma[0] = 0;
        for (int i = 1; i <= n; i++) suma[i] = suma[i - 1] + a[i - 1];

        ll ans = 0;
        queue<pair<ll, int>> q;
        q.emplace(0, 1);
        for (int i = 0; i < n; i++) {
            int cur = 0;
            while (!q.empty() && suma[i + 1] - q.front().first > x) {
                cur += q.front().second;
                q.pop();
            }
            q.emplace(suma[i + 1], cur + 1);
            ans += i + 1 - cur;
        }

        cout << ans << '\n';
    }
}