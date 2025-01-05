#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const ll mx = 1ll << 60;
    ll a; cin >> a;
    int cnt = 0;
    for (ll b = 1; b <= mx; b <<= 1) {
        if (!(a & b) && (a & (b << 1))) {
            ll aa = (a & ~(b - 1)) - b;
            for (ll bb = b >> 1; cnt; cnt--, bb >>= 1) aa |= bb;
            cout << aa << ' ';
            break;
        } else if (b == mx) {
            cout << 0 << ' ';
        } else if (a & b) {
            cnt++;
        }
    }
    cnt = 0;
    for (ll b = 1; b <= mx; b <<= 1) {
        if ((a & b) && !(a & (b << 1))) {
            cout << (((a + b) & ~(b - 1)) | ((1ll << cnt) - 1)) << '\n';
            break;
        } else if (a & b) {
            cnt++;
        }
    }
}