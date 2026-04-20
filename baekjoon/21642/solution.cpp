#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, s;
    cin >> n >> m >> s;
    vector<int> a(m);
    for (int &a: a) cin >> a;
    a.push_back(0);
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());

    int sz = a.size(), ans = 0;
    for (int i = 1; i + m - s - 1 < sz; i++) {
        if (a[i + m - s - 1] < a[i] + m) ans += max(min(a[i], n - m + 1) - max(a[i - 1], a[i + m - s - 1] - m), 0);
    }
    cout << ans << '\n';
}