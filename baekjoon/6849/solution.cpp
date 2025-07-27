#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k, w;
        cin >> n >> k >> w;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        vector<int> pref(n + 1);
        pref[0] = 0;
        for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i - 1];

        vector<vector<int>> sum(n + 1, vector<int>(k + 1, 0));
        for (int i = 0; i < w; i++) sum[i][1] = pref[i];
        for (int i = w; i <= n; i++) {
            for (int j = 1; j <= k; j++) sum[i][j] = max(sum[i - 1][j], sum[i - w][j - 1] + pref[i] - pref[i - w]);
        }

        cout << *max_element(sum[n].begin(), sum[n].end()) << '\n';
    }
}