#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 1e9 * 2 + 1;

int a[600000];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int T; cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int n; cin >> n;
        int m = 2 * n - 1;
        for (int i = 0; i < m; i++) cin >> a[i];
        if (n == 1) {
            cout << "Case #" << tc << ": " << 1 << '\n';
            continue;
        }

        sort(a, a + m);
        int cnds[3] = {a[0] + a[m - 1], a[1] + a[m - 1], a[0] + a[m - 2]};
        int ans = inf;

        for (int k: cnds) {
            bool poss = true;
            int w = inf;
            int l = 0, r = m - 1;

            while (l < r) {
                if (a[l] + a[r] != k) {
                    if (w < inf) {
                        poss = false;
                        break;
                    } else {
                        if (a[l] + a[r] < k) {
                            w = k - a[l];
                            l++;
                        } else {
                            w = k - a[r];
                            r--;
                        }
                        continue;
                    }
                }
                l++;
                r--;
            }

            if (l == r) w = k - a[l];
            if (w > 0 && poss) ans = min(ans, w);
        }
        
        if (ans == inf) ans = -1;
        cout << "Case #" << tc << ": " << ans << '\n';
    }
}