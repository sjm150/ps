#include <iostream>

using namespace std;

int w[100], v[100];
int maxv[100001];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    for (int i = 0; i < n; i++) {
        for (int j = k; j >= w[i]; j--) {
            maxv[j] = max(maxv[j], maxv[j - w[i]] + v[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i <= k; i++) ans = max(ans, maxv[i]);
    cout << ans << '\n';
}