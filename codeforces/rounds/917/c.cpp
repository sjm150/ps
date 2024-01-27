#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k, d; cin >> n >> k >> d;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> v(k);
        for (int i = 0; i < k; i++) cin >> v[i];

        int maxc = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == i + 1) maxc++;
        }
        maxc += (d - 1) / 2;
        for (int i = 0; i < min(2 * n + 1, d - 1); i++) {
            for (int j = 0; j < v[i % k]; j++) a[j]++;
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (a[j] == j + 1) cnt++;
            }
            maxc = max(maxc, cnt + (d - 2 - i) / 2);
        }

        cout << maxc << '\n';
    }
}