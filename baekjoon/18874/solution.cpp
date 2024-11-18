#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    typedef struct Fwtree {
        vector<int> val;
        Fwtree(int n): val(n + 1, 0) {}
        void add(int i) {
            i++;
            while (i < val.size()) {
                val[i]++;
                i += i & -i;
            }
        }
        int get(int i) {
            i++;
            int ret = 0;
            while (i) {
                ret += val[i];
                i &= i - 1;
            }
            return ret;
        }
    } fwt_t;

    int n; cin >> n;
    vector<ll> a(n), ord(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ord[i] = a[i];
    }
    sort(ord.begin(), ord.end());
    ord.resize(unique(ord.begin(), ord.end()) - ord.begin());

    vector<int> bc(n);
    fwt_t fwt(ord.size());
    for (int i = 0; i < n; i++) {
        int o = lower_bound(ord.begin(), ord.end(), a[i]) - ord.begin();
        bc[i] = i - fwt.get(o);
        fwt.add(o);
    }

    vector<vector<int>> pos(n);
    for (int i = 0; i < n; i++) {
        if (a[i] < n) pos[a[i]].push_back(i);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cout << ans << '\n';
        for (int p: pos[i]) ans += bc[p];
    }
}