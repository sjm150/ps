#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
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
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n, m, k; cin >> n >> m >> k;
        vector<pair<int, int>> p(k);
        for (auto &[s, e]: p) cin >> s >> e;
        sort(p.begin(), p.end());
        long long ans = 0;
        fwt_t fwt(m + 1);
        for (auto [s, e]: p) {
            ans += fwt.get(m) - fwt.get(e);
            fwt.add(e);
        }
        cout << "Test case " << tt << ": " << ans << '\n';
    }
}