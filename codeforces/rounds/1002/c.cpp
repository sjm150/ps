#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<ll>> a(n, vector<ll>(n));
        for (auto &a: a) {
            for (ll &a: a) cin >> a;
            a.push_back(0);
            for (int i = n; i; i--) a[i - 1] += a[i];
        }
        int lim = 1, mex = 1;
        for (int i = n - 1; i >= lim; i--, mex++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (a[j][i] == mex) cnt++;
            }
            if (cnt == 0) break;
            lim = max(lim, i - cnt + 1);
        }
        cout << mex << '\n';
    }
}