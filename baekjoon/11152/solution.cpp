#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    const ll mx = 31630;

    vector<bool> isp(mx, true);
    vector<int> p;
    for (ll i = 2; i < mx; i++) {
        if (!isp[i]) continue;
        p.push_back(i);
        for (ll j = i * i; j < mx; j += i) isp[j] = false;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<pair<int, int>>> sod;
        for (int p: p) {
            if (p > n) break;
            vector<pair<int, int>> cur;
            for (ll j = p * p; (j - 1) / (p - 1) <= n; j *= p) {
                int s = (j - 1) / (p - 1);
                if (n % s == 0) cur.emplace_back(s, j / p);
            }
            if (!cur.empty()) sod.push_back(cur);
        }
        int ssz = sod.size();

        vector<int> ans;
        function<void(int, int, int)> sel = [&](int i, int cur, int rem) {
            if (rem == 1) {
                ans.push_back(cur);
                return;
            }
            if (i == ssz) {
                if (rem - 1 >= mx) {
                    bool ok = true;
                    for (int p: p) {
                        if (p * p > rem - 1) break;
                        if ((rem - 1) % p == 0) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) ans.push_back(cur * (rem - 1));
                }
                return;
            }

            sel(i + 1, cur, rem);

            int sz = sod[i].size();
            for (int j = 0; j < sz; j++) {
                auto [s, x] = sod[i][j];
                if (s > rem) break;
                if (rem % s == 0) sel(i + 1, cur * x, rem / s);
            }
        };
        sel(0, 1, n);

        if (ans.empty()) {
            cout << "none!\n";
        } else {
            sort(ans.begin(), ans.end());
            for (int a: ans) cout << a << ' ';
            cout << '\n';
        }
    }
}