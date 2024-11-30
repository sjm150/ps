#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int n, k; cin >> n >> k;
    vector<vector<ll>> v(n, vector<ll>(n, 0)), s(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> v[i][j];
            s[i][j] = v[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i; j++) v[i][j] += v[i][j - 1];
        for (int j = i; j; j--) v[i][j] += v[i - 1][j - 1];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) s[i][j] += (i ? s[i - 1][j] : 0) + (j ? s[i][j - 1] : 0) - (i && j ? s[i - 1][j - 1] : 0);
    }
    ll ans = -1e18;
    for (int i = k - 1; i < n; i++) {
        for (int j = k - 1; j <= i; j++) {
            for (int l = k; j - l + 1 >= 0; l++) {
                ll sum = v[i][j] - (i - l >= 0 && j - l >= 0 ? v[i - l][j - l] : 0) - (j - l >= 0 ? s[i][j - l] - (i - l >= 0 ? s[i - l][j - l] : 0) : 0);
                ans = max(ans, sum / (l * (l + 1) / 2));
            }
        }
    }
    for (int i = 0; i + k - 1 < n; i++) {
        for (int j = k - 1; j <= i; j++) {
            for (int l = k; j - l + 1 >= 0 && i + l - 1 < n; l++) {
                ll sum = s[i + l - 1][j] - (i ? s[i - 1][j] : 0) - (j ? (v[i + l - 1][j - 1] - (i && j - l - 1 >= 0 ? v[i - 1][j - l - 1] : 0)) : 0);
                ans = max(ans, sum / (l * (l + 1) / 2));
            }
        }
    }
    cout << ans << '\n';
}