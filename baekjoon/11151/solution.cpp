#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef struct P {
        int w, c, f;
        P() {}
    } p_t;
    int t; cin >> t;
    while (t--) {
        int n, w, c, f; cin >> n >> w >> c >> f;
        vector<p_t> wcf(n);
        for (auto &[w, c, f]: wcf) cin >> w >> c >> f;
        int sz = 1 << n, ans = n + 1;
        for (int i = 0; i < sz; i++) {
            int sw = 0, sc = 0, sf = 0, cnt = 0;
            for (int j = 0; j < n; j++) {
                if ((1 << j) & i) {
                    sw += wcf[j].w;
                    sc += wcf[j].c;
                    sf += wcf[j].f;
                    cnt++;
                }
            }
            if (sw >= w && sc >= c && sf >= f) ans = min(ans, cnt);
        }
        if (ans > n) cout << "game over\n";
        else cout << ans << '\n';
    }
}