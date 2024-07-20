#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<int> s(n);
    for (int &s: s) cin >> s;

    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int mx = s[i - 1];
        for (int j = 1; j <= k && i - j >= 0; j++) {
            sum[i] = max(sum[i], sum[i - j] + j * mx);
            if (i - j - 1 >= 0) mx = max(mx, s[i - j - 1]);
        }
    }

    cout << sum[n] << '\n';
}