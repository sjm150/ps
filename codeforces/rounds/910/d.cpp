#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        int maxa = 0, minb = 1e9 + 1;
        long long sum = 0;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) {
            int b; cin >> b;
            sum += abs(a[i] - b);
            maxa = max(maxa, min(a[i], b));
            minb = min(minb, max(a[i], b));
        }
        cout << sum + 2 * max(0, maxa - minb) << '\n';
    }
}