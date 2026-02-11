#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int l, d, n;
    cin >> l >> d >> n;
    vector<int> p(n);
    for (int &p: p) cin >> p;
    sort(p.begin(), p.end());
    int ans = l < 12 ? 0 : p.empty() ? max(0, l - 12) / d + 1 : max(0, p[0] - 6) / d + max(0, l - 6 - p.back()) / d;
    for (int i = 0; i < n - 1; i++) ans += max(0, p[i + 1] - p[i] - d) / d;
    cout << ans << '\n';
}