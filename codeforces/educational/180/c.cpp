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
        sort(a.begin(), a.end());

        int mx = a.back();
        a.pop_back();
        n--;

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans += max(0, int(lower_bound(a.begin() + j + 1, a.end(), a[i] + a[j]) - upper_bound(a.begin() + j + 1, a.end(), mx - a[i] - a[j])));
                if (a[i] + a[j] > mx) ans++;
            }
        }
        cout << ans << '\n';
    }
}