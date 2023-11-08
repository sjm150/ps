#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int m; cin >> m;
        map<ll, vector<pair<ll, ll>>> mapt;
        vector<ll> l(m), r(m), crd(m);
        ll nt = 0, lt = 0, rt = 0;
        for (int i = 0; i < m; i++) {
            int n; cin >> n >> l[i] >> r[i];
            nt += n, lt += l[i], rt += r[i];
            vector<ll> a(n);
            for (int j = 0; j < n; j++) cin >> a[j];
            for (int j = 0; j < n; j++) {
                ll c; cin >> c;
                crd[i] += c;
                mapt[a[j]].emplace_back(i, c);
            }
        }

        if (rt - lt >= nt) {
            cout << 0 << '\n';
            continue;
        }

        ll mab = rt;
        for (ll len = lt; len <= rt; len++) {
            ll sum = rt, ab = 0;
            for (auto [i, cnt]: mapt[len]) {
                sum -= r[i];
                if (l[i] <= crd[i] - cnt) {
                    sum += min(r[i], crd[i] - cnt);
                } else {
                    sum += l[i];
                    ab += l[i] - crd[i] + cnt;
                }
            }
            if (sum < len) ab += len - sum;
            mab = min(mab, ab);
        }

        cout << mab << '\n';
    }
}