#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int &a: a) cin >> a;
    for (int &b: b) cin >> b;
    sort(b.begin(), b.end());
    int ans = 0;
    for (int a: a) {
        int idx = lower_bound(b.begin(), b.end(), a) - b.begin();
        int cur = 1e9;
        if (idx > 0) cur = min(cur, a - b[idx - 1]);
        if (idx < n) cur = min(cur, b[idx] - a);
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}