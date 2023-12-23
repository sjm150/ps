#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 63246;

vector<int> get_prms() {
    vector<bool> prm(mx + 1, true);
    vector<int> prms;
    for (ll i = 2; i <= mx; i++) {
        if (!prm[i]) continue;
        prms.push_back(i);
        for (ll j = i * i; j <= mx; j += i) prm[j] = false;
    }
    return prms;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    vector<int> prms = get_prms();
    while (t--) {
        ll n; cin >> n;
        if (n <= 2) {
            cout << 2 << '\n';
            continue;
        }
        for (ll i = n; ; i++) {
            bool prm = true;
            for (int p: prms) {
                if (ll(p) * p > i) break;
                if (i % p == 0) {
                    prm = false;
                    break;
                }
            }
            if (prm) {
                cout << i << '\n';
                break;
            }
        }
    }
}