#include <bits/stdc++.h>
using namespace std;

int idx[int(1e6 + 1)];

typedef struct Fwtree {
    vector<int> val;
    Fwtree(int n) { val.resize(n + 1, 0); }

    void add(int idx, int v) {
        idx++;
        while (idx < val.size()) {
            val[idx] += v;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        idx++;
        int v = 0;
        while (idx) {
            v += val[idx];
            idx &= idx - 1;
        }
        return v;
    }
} fwt_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        idx[a] = i;
    }
    vector<int> con(n);
    for (int i = 0; i < n; i++) {
        int b; cin >> b;
        con[i] = idx[b];
    }

    fwt_t fwt(n);
    long long cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        cnt += fwt.query(con[i]);
        fwt.add(con[i], 1);
    }
    cout << cnt << '\n';
}