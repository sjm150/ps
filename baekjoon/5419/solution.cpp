#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

typedef struct Bitree {
    vector<int> val;
    Bitree(int n): val(n + 1, 0) {};
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
} bit_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pi> xy(n);
        for (auto &[x, y]: xy) cin >> x >> y;
        sort(xy.begin(), xy.end(), [](pi &a, pi &b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        bit_t bit(n);
        vector<int> ys;
        for (auto &[x, y]: xy) ys.push_back(y);
        sort(ys.begin(), ys.end());
        long long ans = 0;
        for (auto &[x, y]: xy) {
            int idx = lower_bound(ys.begin(), ys.end(), y) - ys.begin();
            ans += bit.get(n - 1) - bit.get(idx - 1);
            bit.add(idx);
        }
        cout << ans << '\n';
    }
}