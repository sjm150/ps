#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int sum = 0;
        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) sum += a[i * 2];
        cout << sum << '\n';
    }
}