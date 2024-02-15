#include <bits/stdc++.h>
using namespace std;

typedef struct Fwtree {
    vector<int> val;
    Fwtree(int n) { val.resize(n + 1, 0); }

    void add(int i, int v) {
        while (i < val.size()) {
            val[i] += v;
            i += i & -i;
        }
    }

    int get(int i) {
        int ret = 0;
        while (i) {
            ret += val[i];
            i &= i - 1;
        }
        return ret;
    }
} fwt_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> idx(n + 1);
    fwt_t fwt(n);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        idx[x] = i;
    }

    int l = 1, r = n;
    for (; l < r; l++, r--) {
        cout << idx[l] - 1 - fwt.get(idx[l]) << '\n';
        fwt.add(idx[l], 1);
        cout << n - idx[r] - fwt.get(n) + fwt.get(idx[r]) << '\n';
        fwt.add(idx[r], 1);
    }
    if (l == r) cout << idx[l] - 1 - fwt.get(idx[l]) << '\n';
}