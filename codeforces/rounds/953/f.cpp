#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mx = 1e6;

typedef struct Djset {
    vector<int> p;
    Djset(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    int find(int u) {
        if (p[u] == u) return u;
        return p[u] = find(p[u]);
    }
    void uni(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        p[u] = v;
    }
} djs_t;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    vector<int> p;
    vector<bool> prm(mx + 1, true);
    for (ll i = 2; i <= mx; i++) {
        if (!prm[i]) continue;
        p.push_back(i);
        for (ll j = i * i; j <= mx; j += i) prm[j] = false;
    }

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        reverse(a.begin(), a.end());
        for (int i = 0; i < n - 1; i++) a.push_back(a[i]);
        int sz = a.size();

        vector<vector<int>> pf(n);
        for (int i = 0; i < n; i++) {
            int x = a[i];
            for (int p: p) {
                if (ll(p) * p > x) break;
                if (x % p == 0) pf[i].push_back(p);
                while (x % p == 0) x /= p;
            }
            if (x != 1) pf[i].push_back(x);
        }

        unordered_map<int, vector<int>> pidx;
        for (int i = 0; i < sz; i++) {
            for (int p: pf[i < n ? i : i - n]) {
                pidx[p].push_back(i);
            }
        }

        djs_t djs(sz);
        for (int i = 0; i < sz; i++) {
            for (int p: pf[i < n ? i : i - n]) {
                auto &ind = pidx[p];
                int idx = lower_bound(ind.begin(), ind.end(), i) - ind.begin();
                if (idx && i - ind[idx - 1] <= k) djs.uni(i, ind[idx - 1]);
            }
        }

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) ans++;
        }
        ans *= n;
        for (int i = 0; i < sz; i++) {
            if (a[i] != 1 && djs.p[i] == i) ans++;
        }

        cout << ans << '\n';
    }
}