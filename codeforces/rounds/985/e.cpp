#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const int mx = 4e5 + 1;
    vector<int> mnd(mx);
    iota(mnd.begin(), mnd.end(), 0);
    for (ll i = 2; i < mx; i++) {
        if (mnd[i] != i) continue;
        for (ll j = i * i; j < mx; j += i) {
            if (mnd[j] == j) mnd[j] = i;
        }
    }

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;

        bool ok = true;
        int p = -1;
        for (int a: a) {
            if (mnd[a] == a) {
                if (p < 0) {
                    p = a;
                } else {
                    ok = false;
                    break;
                }
            }
        }

        if (p <= 2) {
            p = 2;
        } else if (ok) {
            for (int a: a) {
                if (a % p == 0) continue;
                if (a - mnd[a] >= 2 * p) continue;
                ok = false;
                break;
            }
        }
        cout << (ok ? p : -1) << '\n';
    }
}