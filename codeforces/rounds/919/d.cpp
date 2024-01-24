#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll lim = 1e18;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;

        ll sz = 0;
        bool over = false;
        map<ll, int> arr;
        set<ll> mod;
        while (n--) {
            int b, x; cin >> b >> x;
            if (over) continue;
            if (b == 1) {
                arr[sz++] = x;
                if (sz > lim) over = true;
            } else {
                mod.insert(sz);
                x++;
                if (sz > (lim + x - 1) / x) over = true;
                else sz *= x;
            }
        }

        while (q--) {
            ll k; cin >> k;
            k--;
            while (arr.find(k) == arr.end()) k %= *prev(mod.upper_bound(k));
            cout << arr[k] << ' ';
        }
        cout << '\n';
    }
}