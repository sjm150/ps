#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        ll ans = 0;
        for (int &a: a) cin >> a;

        for (int i = 0; i < 2; i++) {
            vector<int> cnt(n + 1, 0);
            int mad = 0;
            for (int &a: a) {
                ans += a;
                cnt[a]++;
                if (cnt[a] >= 2 && mad < a) mad = a;
                else a = mad;
            }
        }

        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            ans += sum;
        }

        cout << ans << '\n';
    }
}