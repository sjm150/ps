#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        long long sum = a[0] ^ a[n - 1];
        for (int i = 1; i < n; i++) sum += a[i - 1] ^ a[i];
        cout << sum << '\n';
    }
}