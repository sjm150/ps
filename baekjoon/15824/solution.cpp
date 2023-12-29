#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> scv(n);
    for (int i = 0; i < n; i++) cin >> scv[i];
    sort(scv.begin(), scv.end());

    ll cnt = 1, ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + scv[i] * cnt) % mod;
        cnt <<= 1;
        if (cnt >= mod) cnt -= mod;
    }
    cnt = 1;
    for (int i = n - 1; i >= 0; i--) {
        ans = ((ans - scv[i] * cnt) % mod + mod) % mod;
        cnt <<= 1;
        if (cnt >= mod) cnt -= mod;
    }

    cout << ans << '\n';
}