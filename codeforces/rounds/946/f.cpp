#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int a, b, n, m; cin >> a >> b >> n >> m;
        set<pi> xy, yx;
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            xy.emplace(x, y);
            yx.emplace(y, x);
        }

        int u = 1, d = a, l = 1, r = b;
        int score[] = {0, 0};
        for (int i = 0; i < m; i++) {
            char c; cin >> c;
            int k; cin >> k;
            if (c == 'U') {
                u += k;
                auto it = xy.begin();
                while (it != xy.end() && it->first < u) {
                    yx.erase(pi(it->second, it->first));
                    it = xy.erase(it);
                    score[i & 1]++;
                }
            } else if (c == 'D') {
                d -= k;
                auto it = xy.lower_bound(pi(d + 1, 0));
                while (it != xy.end()) {
                    yx.erase(pi(it->second, it->first));
                    it = xy.erase(it);
                    score[i & 1]++;
                }
            } else if (c == 'L') {
                l += k;
                auto it = yx.begin();
                while (it != yx.end() && it->first < l) {
                    xy.erase(pi(it->second, it->first));
                    it = yx.erase(it);
                    score[i & 1]++;
                }
            } else {
                r -= k;
                auto it = yx.lower_bound(pi(r + 1, 0));
                while (it != yx.end()) {
                    xy.erase(pi(it->second, it->first));
                    it = yx.erase(it);
                    score[i & 1]++;
                }
            }
        }

        cout << score[0] << ' ' << score[1] << '\n';
    }
}