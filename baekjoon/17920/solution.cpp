#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    for (int i = 0; i < n; i++) a[i] = a[i] * 100 + i * k;
    int ans = 0, mx = 0;
    for (int a: a) {
        mx = max(mx, a);
        ans = max(ans, mx - a - k);
    }
    cout << ans << '\n';
}