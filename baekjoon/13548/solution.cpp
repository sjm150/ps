#include <bits/stdc++.h>
using namespace std;

typedef struct Q {
    int i, l, r, res;
    Q() {}
    Q(int i, int l, int r): i(i), l(l), r(r) {}
} q_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    int m; cin >> m;
    vector<q_t> q(m);
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        q[i] = Q(i, l - 1, r - 1);
    }
    int u = sqrt(n);
    sort(q.begin(), q.end(), [&](q_t &a, q_t &b) {
        if (a.l / u == b.l / u) return a.r < b.r;
        return a.l / u < b.l / u;
    });

    vector<int> cnt(*max_element(a.begin(), a.end()) + 1, 0);
    vector<int> ccnt(n, 0);
    int mx = 0;
    ccnt[0] = n;
    auto add = [&](int a) {
        cnt[a]++;
        ccnt[cnt[a]]++;
        if (cnt[a] > mx) mx = cnt[a];
    };
    auto sub = [&](int a) {
        ccnt[cnt[a]]--;
        cnt[a]--;
        if (ccnt[mx] == 0) mx--;
    };

    for (int i = q[0].l; i <= q[0].r; i++) add(a[i]);
    q[0].res = mx;
    for (int i = 1; i < m; i++) {
        if (q[i].r < q[i - 1].r) {
            for (int j = q[i - 1].r; j > q[i].r; j--) sub(a[j]);
        } else {
            for (int j = q[i].r; j > q[i - 1].r; j--) add(a[j]);
        }
        if (q[i].l < q[i - 1].l) {
            for (int j = q[i].l; j < q[i - 1].l; j++) add(a[j]);
        } else {
            for (int j = q[i - 1].l; j < q[i].l; j++) sub(a[j]);
        }
        q[i].res = mx;
    }

    sort(q.begin(), q.end(), [](q_t &a, q_t &b) { return a.i < b.i; });
    for (auto &q: q) cout << q.res << '\n';
}