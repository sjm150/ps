#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n), b(n);
        for (ll &a: a) cin >> a;
        for (ll &b: b) cin >> b;

        int r = min_element(b.begin(), b.end()) - b.begin();
        vector<int> lc(n, -1), rc(n, -1);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && b[stk.top()] > b[i]) stk.pop();
            if (!stk.empty()) rc[stk.top()] = i;
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && b[stk.top()] >= b[i]) stk.pop();
            if (!stk.empty()) lc[stk.top()] = i;
            stk.push(i);
        }

        vector<vector<ll>> mx(n, vector<ll>(64));
        for (int i = 0; i < n; i++) fill(mx[i].begin(), mx[i].end(), a[i]);
        function<void(int)> dfs = [&](int cur) {
            if (lc[cur] >= 0) dfs(lc[cur]);
            if (rc[cur] >= 0) dfs(rc[cur]);
            if (lc[cur] >= 0 && rc[cur] >= 0) {
                int li = 0, ri = 0;
                for (int i = 0; i < 64; i++) {
                    mx[cur][i] = max(mx[cur][i], max(mx[lc[cur]][li], mx[rc[cur]][ri]));
                    if (li == 63) ri++;
                    else if (ri == 63) li++;
                    else if (mx[lc[cur]][li] > mx[rc[cur]][ri]) li++;
                    else ri++;
                }
            } else if (lc[cur] >= 0) {
                for (int i = 0; i < 64; i++) mx[cur][i] = max(mx[cur][i], mx[lc[cur]][i]);
            } else if (rc[cur] >= 0) {
                for (int i = 0; i < 64; i++) mx[cur][i] = max(mx[cur][i], mx[rc[cur]][i]);
            }
            for (int i = 1; i < 64; i++) mx[cur][i] = min(mx[cur][i], (mx[cur][i - 1] + b[cur] - 1) / b[cur]);
        };
        dfs(r);

        int ans = 0;
        while (ans < 64 && mx[r][ans] > 1) ans++;
        cout << ans << '\n';
    }
}