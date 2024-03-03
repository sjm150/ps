#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int l, r; cin >> l >> r;
    if (l > r) swap(l, r);
    ll x, y; cin >> x >> y;
    x = abs(x);
    if (y < 0 || y >= x) {
        cout << "Unknwon Number\n";
        return 0;
    }

    ll cur = l;
    ll cr = (cur % x + x) % x;
    if (cr > y) cur += x - cr + y;
    else cur += y - cr;

    if (cur > r || cur + x <= r) cout << "Unknwon Number\n";
    else cout << cur << '\n';
}