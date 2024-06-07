#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> k(n);
        for (int &k: k) cin >> k;
        int mxk = *max_element(k.begin(), k.end());
        ll st = ll(1e9) * *min_element(k.begin(), k.end()) / mxk;

        vector<int> x(n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            x[i] = st * mxk / k[i];
            sum += x[i];
        }

        bool poss = true;
        for (int i = 0; i < n; i++) {
            if (ll(x[i]) * k[i] <= sum) {
                poss = false;
                break;
            }
        }

        if (poss) {
            for (int x: x) cout << x << ' ';
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}