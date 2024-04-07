#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        --k;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        int i = 0;
        for (; i < n; i++) {
            if (a[i] > a[k]) break;
        }
        int ans = max(0, i - 1);

        if (i < k) {
            swap(a[i], a[k]);
            int len = i > 0;
            for (int j = i + 1; j <= k; j++) {
                if (a[j] > a[i]) {
                    ans = max(ans, len);
                    break;
                }
                len++;
            }
        }

        cout << ans << '\n';
    }
}