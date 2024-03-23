#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        vector<ll> dp(n);
        dp[0] = max(a[0], 0);
        for (int i = 1; i < n; i++) dp[i] = max(a[i] + dp[i - 1], 0ll);

        ll maxs = *max_element(dp.begin(), dp.end());
        ll sum = -maxs;
        for (int a: a) sum += a;
        maxs %= mod;
        while (k--) maxs = maxs * 2 % mod;
        cout << ((sum + maxs) % mod + mod) % mod << '\n';
    }
}