#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> h(n);
    for (int &h: h) cin >> h;
    sort(h.begin(), h.end());
    int sz = n / 2, ans = h[n - 1] - h[0];
    for (int i = sz; i < n; i++) ans = min(ans, h[i] - h[i - sz]);
    cout << ans << '\n';
}