#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> a(m), d(m + 1);
    for (int &a: a) cin >> a;
    d[0] = a[0] - 1;
    d[m] = n + 1 - a[m - 1];
    for (int i = 1; i < m; i++) {
        d[i] = a[i] - a[i - 1];
        if (d[i] < 0) d[i] += n;
    }
    sort(d.begin(), d.end());
    int cnt = accumulate(d.begin(), d.end(), 0ll) / n;
    for (int i = m; m - cnt < i; i--) d[i] = n - d[i];
    cout << accumulate(d.begin(), d.end(), 0ll) << '\n';
}