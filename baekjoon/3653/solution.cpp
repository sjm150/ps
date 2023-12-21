#include <bits/stdc++.h>
using namespace std;

typedef struct FwTree {
    vector<int> val;
    FwTree(int n): val(n + 1, 0) {}

    void add(int i, int v) {
        i++;
        while (i < val.size()) {
            val[i] += v;
            i += i & -i;
        }
    }

    int query(int i) {
        i++;
        int v = 0;
        while (i) {
            v += val[i];
            i &= i - 1;
        }
        return v;
    }
} fwt_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        int pidx = 0;
        vector<int> pos(n + 1);
        fwt_t fwt(n + m + 1);
        for (int i = n; i >= 1; i--) {
            pos[i] = pidx;
            fwt.add(pidx, 1);
            pidx++;
        }

        while (m--) {
            int i; cin >> i;
            int p = pos[i];
            cout << n - fwt.query(p) << ' ';
            pos[i] = pidx;
            fwt.add(p, -1);
            fwt.add(pidx, 1);
            pidx++;
        }
        cout << '\n';
    }
}