#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> cnt2(n, 0), cnt5(n, 0);
        for (int i = 0; i < n; i++) {
            int s; cin >> s;
            for (; s % 2 == 0; s /= 2) cnt2[i]++;
            for (; s % 5 == 0; s /= 5) cnt5[i]++;
        }
        vector<int> sum2(n), sum5(n);
        sum2[0] = cnt2[0];
        sum5[0] = cnt5[0];
        for (int i = 1; i < n; i++) {
            int mn2 = 1e9, mn5 = 1e9;
            for (int j = i - 1; j >= max(0, i - k); j--) {
                mn2 = min(mn2, sum2[j]);
                mn5 = min(mn5, sum5[j]);
            }
            sum2[i] = mn2 + cnt2[i];
            sum5[i] = mn5 + cnt5[i];
        }
        cout << min(sum2[n - 1], sum5[n - 1]) << '\n';
    }
}