#include <iostream>

using namespace std;

int t[1500000], p[1500000], sum[1500001];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> t[i] >> p[i];
    sum[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum[i] = sum[i + 1];
        if (i + t[i] <= n) {
            sum[i] = max(sum[i], p[i] + sum[i + t[i]]);
        }
    }
    cout << sum[0] << '\n';
}