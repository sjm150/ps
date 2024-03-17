#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> cnt(n);
        cnt[0] = 0;
        cnt[1] = a[0];
        if (a[1] - 2 * cnt[1] < 0) {
            cout << "NO\n";
            continue;
        }

        bool poss = true;
        for (int i = 2; i < n - 1; i++) {
            cnt[i] = a[i - 1] - 2 * cnt[i - 1] - cnt[i - 2];
            // cout << a[i] - 2 * cnt[i] - cnt[i - 1] << ' ';
            if (a[i] - 2 * cnt[i] - cnt[i - 1] < 0) {
                poss = false;
                break;
            }
        }
        if (a[n - 2] - 2 * cnt[n - 2] - cnt[n - 3] != 0) poss = false;
        if (a[n - 1] - 2 * cnt[n - 1] - cnt[n - 2] != 0) poss = false;

        if (poss) cout << "YES\n";
        else cout << "NO\n";
    }
}