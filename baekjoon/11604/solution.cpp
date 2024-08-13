#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, w; cin >> n >> w;
    double pp = 1, safe = 0, fsum = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        double p; cin >> p;
        int v; cin >> v;
        double sval = log(1 + double(v) / w);
        fsum += pp * (1 - p) * safe;
        ans = max(ans, (exp(pp * p * sval + fsum) - 1) * w);
        pp *= p;
        if (s[0] == 's') safe = sval;
    }
    cout << '$' << fixed << setprecision(2) << ans << '\n';
}