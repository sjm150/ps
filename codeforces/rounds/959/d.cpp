#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        
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
            bool uni(int u, int v) {
                u = find(u), v = find(v);
                if (u == v) return false;
                p[u] = v;
                return true;
            }
        } djs_t;

        djs_t djs(n);
        vector<int> r(n);
        vector<pair<int, int>> ans(n - 1);
        for (int i = n - 1; i; i--) {
            vector<int> pre(i, -1);
            for (int j = 0; j < n; j++) {
                int r = a[j] % i;
                if (pre[r] >= 0 && djs.uni(pre[r], j)) {
                    ans[i - 1] = {pre[r] + 1, j + 1};
                    break;
                }
                pre[r] = j;
            }
        }

        cout << "YES\n";
        for (auto &[u, v]: ans) cout << u << ' ' << v << '\n';
    }
}