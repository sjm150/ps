#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string w, d, m; cin >> w >> d >> m;
        int ans = 0, dup[3] = {}, sol = 0;
        for (int i = 0; i < n; i++) {
            if (w[i] == d[i] && d[i] == m[i]) ans++;
            else if (w[i] == d[i]) dup[0]++;
            else if (d[i] == m[i]) dup[1]++;
            else if (w[i] == m[i]) dup[2]++;
            else sol++;
        }
        for (; sol; sol--) {
            int idx = max_element(dup, dup + 3) - dup;
            if (dup[idx] == 0) break;
            dup[idx]--;
            ans++;
        }
        int mn = *min_element(dup, dup + 3);
        ans += 2 * mn;
        for (int &d: dup) d -= mn;
        ans += accumulate(dup, dup + 3, 0) / 2;
        ans += sol / 3;
        cout << ans << '\n';
    }
}