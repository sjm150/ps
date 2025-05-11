#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        vector<ll> mn(n);
        for (int i = 0; i < n; i++) {
            mn[i] = (i > 0 ? mn[i - 1] : 0) + a[i];
            for (int j = 0; j < i; j++) {
                mn[i] = min(mn[i], min(
                    (j > 0 ? mn[j - 1] : 0) + ll(i - j + 1) * (a[i] + 1) - 1,
                    mn[j] + i - j + ll(i - j) * (a[j] + 1)
                ));
            }
        }
        cout << mn[n - 1] << '\n';
    }
}