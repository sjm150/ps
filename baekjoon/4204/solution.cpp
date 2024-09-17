#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const ld eps = 1e-9;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, t = 1;
    while (cin >> n) {
        vector<ld> a(n + 1);
        for (auto &a: a) cin >> a;
        ld l, h; cin >> l >> h;
        int v; cin >> v;

        vector<ld> f(2 * n + 1, 0);
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                f[i + j] += a[i] * a[j];
            }
        }
        for (int i = 0; i <= 2 * n; i++) f[i] /= i + 1;

        auto vol = [&](ld x) {
            ld ret = 0, cur = x;
            for (int i = 0; i <= 2 * n; i++) {
                ret += f[i] * cur;
                cur *= x;
            }
            return ret * M_PI;
        };

        ld lv = vol(l), hv = vol(h);
        cout << fixed << setprecision(2);
        cout << "Case " << t++ << ": " << hv - lv << '\n';
        bool ok = false;
        for (int i = 0; i < 8; i++) {
            ld tv = v * (i + 1);
            if (tv > hv - lv) break;
            ld lx = l, rx = h;
            while (rx - lx > eps) {
                ld m = (lx + rx) / 2;
                if (vol(m) - lv > tv) rx = m;
                else lx = m;
            }
            if (h - rx < 1e-2) break;
            ok = true;
            cout << lx - l << ' ';
        }
        cout << (ok ? "\n" : "insufficient volume\n");
    }
}