#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        vector<int> a(n + 1);
        a[0] = 0;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int minv = (x - a[n]) * 2;
        for (int i = 0; i < n; i++) minv = max(minv, a[i + 1] - a[i]);
        cout << minv << '\n';
    }
}