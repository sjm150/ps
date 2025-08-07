#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const int mod = 1e9 + 7;
    int n;
    cin >> n;
    ll ans = 0, cnt[2] = {};
    while (n--) {
        int x;
        cin >> x;
        if (x == 1) cnt[0]++;
        else if (x == 2) cnt[1] = (cnt[0] + cnt[1] * 2) % mod;
        else ans += cnt[1];
    }
    cout << ans % mod << '\n';
}