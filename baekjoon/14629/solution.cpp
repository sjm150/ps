#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll n; cin >> n;
    vector<bool> use(10, false);
    ll ans = 1e18;
    function<void(ll, int)> sel = [&](ll cur, int idx) {
        if (idx == 10) return;
        for (int i = 0; i < 10; i++) {
            if (use[i]) continue;
            use[i] = true;
            ll nxt = cur * 10 + i;
            if (abs(nxt - n) < abs(ans - n) || (abs(nxt - n) == abs(ans - n) && nxt < ans)) ans = nxt;
            sel(nxt, idx + 1);
            use[i] = false;
        }
    };
    sel(0, 0);
    cout << ans << '\n';
}