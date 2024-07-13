#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int k; cin >> k;
    int n = (1 << (k + 1)) - 1;
    vector<int> w(n);
    w[0] = 0;
    for (int i = 1; i < n; i++) cin >> w[i];
    int ans = accumulate(w.begin(), w.end(), 0);
    for (int i = n / 2 - 1; i >= 0; i--) {
        ans += abs(w[i * 2 + 1] - w[i * 2 + 2]);
        w[i] += max(w[i * 2 + 1], w[i * 2 + 2]);
    }
    cout << ans << '\n';
}