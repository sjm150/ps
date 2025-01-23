#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef pair<int, int> pi;
    typedef struct Fwtree {
        vector<int> val;
        Fwtree(int n): val(n + 1, 0) {}
        int get(int i) {
            i++;
            int ret = 0;
            while (i) {
                ret += val[i];
                i &= i - 1;
            }
            return ret;
        }
        void add(int i) {
            i++;
            while (i < val.size()) {
                val[i]++;
                i += i & -i;
            }
        }
    } fwt_t;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        long long ans = 0;
        for (int m = 1; m <= 10; m++) {
            vector<pi> lr(n + 1);
            lr[0] = {0, 0};
            for (int i = 1; i <= n; i++) {
                lr[i].first = lr[i - 1].first + (a[i - 1] <= m ? 1 : -1);
                lr[i].second = lr[i - 1].second + (m <= a[i - 1] ? 1 : -1);
            }
            sort(lr.begin(), lr.end(), [](pi &a, pi &b) {
                if (a.first == b.first) return a.second > b.second;
                return a.first < b.first;
            });

            fwt_t fwt(2 * n);
            for (auto [l, r]: lr) {
                ans += fwt.get(r + n - 1);
                fwt.add(r + n);
            }
        }
        cout << ans << '\n';
    }
}