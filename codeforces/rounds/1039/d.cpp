#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int &p: p) cin >> p;

        vector<long long> sum(n);
        sum[0] = 1;
        sum[1] = p[0] > p[1] ? 3 : 2;
        for (int i = 2; i < n; i++) {
            if (p[i - 1] > p[i]) {
                sum[i] = sum[i - 1] + i + 1;
            } else {
                sum[i] = sum[i - 2] + i + 1;
            }
        }

        cout << accumulate(sum.begin(), sum.end(), 0ll) << '\n';
    }
}