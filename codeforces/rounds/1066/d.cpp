#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        ll lv = 0, rv = 0;
        vector<int> rem;
        for (int a: a) {
            if (a <= l) {
                lv += l - a, rv += r - a;
            } else if (r <= a) {
                lv += a - l, rv += a - r;
            } else {
                rem.push_back(a);
            }
        }
        sort(rem.begin(), rem.end());

        for (int a: rem) {
            lv += a - l, rv += a - r;
        }
        ll ans = min(lv, rv);
        for (int a: rem) {
            lv += l - a, rv += r - a;
            ans = max(ans, min(lv, rv));
            lv += l - a, rv += r - a;
            ans = max(ans, min(lv, rv));
        }
        cout << ans << '\n';
    }
}