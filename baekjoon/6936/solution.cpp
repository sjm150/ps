#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (;;) {
        int n; cin >> n;
        if (n == 0) break;
        vector<int> nxt(n + 1);
        for (int i = 0; i < n; i++) {
            int u, v; cin >> u >> v;
            nxt[u] = v;
        }
        vector<bool> vst(n + 1, false);
        function<int(int)> dfs = [&](int cur) {
            vst[cur] = true;
            if (!vst[nxt[cur]]) return dfs(nxt[cur]) + 1;
            else return 1;
        };
        function<int(int, int)> gcd = [&](int a, int b) {
            if (b == 0) return a;
            return gcd(b, a % b);
        };
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!vst[i]) {
                int cnt = dfs(i);
                if (ans) ans *= cnt / gcd(ans, cnt);
                else ans = cnt;
            }
        }
        cout << ans << '\n';
    }
}