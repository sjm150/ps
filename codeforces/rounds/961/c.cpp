#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        ll ans = 0, pre = 0;
        for (int i = 1; i < n; i++) {
            int a1 = a[i - 1], a2 = a[i];
            if (a1 == 1) continue;
            if (a2 == 1) {
                ans = -1;
                break;
            }

            if (a1 <= a2) {
                int d = 0;
                for (ll i = a1; i <= a2; i *= i) d++;
                pre = max(0ll, pre - d + 1);
            } else {
                int d = 0;
                for (ll i = a2; i < a1; i *= i) d++;
                pre += d;
            }
            ans += pre;
        }

        cout << ans << '\n';
    }
}