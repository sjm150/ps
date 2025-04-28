#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        vector<int> mx(n + 1);
        mx[0] = *min_element(a.begin(), a.end());
        for (int i = 0; i < n; i++) mx[i + 1] = max(mx[i], a[i]);

        long long sum = 0;
        for (int k = 1; k <= n; k++) {
            cout << sum + mx[n - k + 1] << ' ';
            sum += a[n - k];
        }
        cout << '\n';
    }
}