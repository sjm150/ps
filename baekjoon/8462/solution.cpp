#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef struct Q {
    int i, l, r;
    Q() {}
    Q(int i, int l, int r): i(i), l(l), r(r) {}
} q_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, t; cin >> n >> t;
    vector<int> a(n);
    for (int &a: a) cin >> a;
    vector<q_t> q(t);
    for (int i = 0; i < t; i++) {
        int l, r; cin >> l >> r;
        q[i] = Q(i, l - 1, r - 1);
    }
    int u = sqrt(n);
    sort(q.begin(), q.end(), [&](q_t &a, q_t &b) {
        if (a.l / u == b.l / u) return a.r < b.r;
        return a.l / u < b.l / u;
    });

    vector<int> cnt(*max_element(a.begin(), a.end()) + 1, 0);
    ll cur = 0;
    auto add = [&](int x) { cur += ll(2 * cnt[x]++ + 1) * x; };
    auto sub = [&](int x) { cur -= ll(2 * --cnt[x] + 1) * x; };

    vector<ll> ans(t);
    int l = q[0].l, r = q[0].r;
    for (int i = l; i <= r; i++) add(a[i]);
    ans[q[0].i] = cur;
    for (int i = 1; i < t; i++) {
        while (q[i].l < l) add(a[--l]);
        while (r < q[i].r) add(a[++r]);
        while (l < q[i].l) sub(a[l++]);
        while (q[i].r < r) sub(a[r--]);
        ans[q[i].i] = cur;
    }

    for (ll a: ans) cout << a << '\n';
}