#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cnt(ll n) {
    int bitcnt = 0;
    ll ret = 0;
    for (int i = 62; i >= 0; i--) {
        ll b = ll(1) << i;
        if ((n & b) == 0) continue;
        ret += b * bitcnt + b / 2 * i;
        bitcnt++;
    }
    return ret;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll a, b; cin >> a >> b;
    cout << cnt(b + 1) - cnt(a) << '\n';
}