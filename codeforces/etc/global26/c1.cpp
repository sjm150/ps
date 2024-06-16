#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
 
        vector<long long> mx(n), mn(n);
        mn[0] = a[0];
        mx[0] = abs(mn[0]);
        for (int i = 1; i < n; i++) {
            mx[i] = max(mx[i - 1] + a[i], abs(mn[i - 1] + a[i]));
            mn[i] = mn[i - 1] + a[i];
        }
 
        cout << mx[n - 1] << '\n';
    }
}