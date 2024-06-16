#include <bits/stdc++.h>
using namespace std;
 
const int mod = 998244353;
 
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
 
        vector<long long> mx(n), mn(n), xc(n), nc(n);
        mn[0] = a[0];
        mx[0] = abs(mn[0]);
        xc[0] = (mn[0] >= 0 ? 2 : 1);
        nc[0] = xc[0];
        for (int i = 1; i < n; i++) {
            long long x1 = mx[i - 1] + a[i], x2 = abs(mn[i - 1] + a[i]);
            mx[i] = max(x1, x2);
            mn[i] = mn[i - 1] + a[i];
 
            if (x1 > x2) {
                xc[i] = (long long)(xc[i - 1]) * 2 % mod;
            } else if (x1 == x2) {
                xc[i] = ((long long)(xc[i - 1]) * 2 + (mx[i - 1] != mn[i - 1] ? nc[i - 1] : 0)) % mod;
            } else {
                xc[i] = nc[i - 1];
            }
 
            if (mn[i - 1] + a[i] >= 0) {
                nc[i] = nc[i - 1] * 2 % mod;
            } else {
                nc[i] = nc[i - 1];
            }
        }
 
        cout << xc[n - 1] << '\n';
    }
}