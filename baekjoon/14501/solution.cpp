#include <iostream>

using namespace std;

int t[16], p[16], sum[16];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i] >> p[i];
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] = 0;
        for (int j = 1; j <= i; j++) {
            if (j + t[j] - 1 <= i) {
                sum[i] = max(sum[i], sum[j - 1] + p[j]);
            }
        }
    }
    cout << sum[n] << '\n';
}