#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    int p, q; cin >> p >> q;

    vector<int> s(q + 1, 0);
    vector<bool> sel(n, false);
    int ans = 0;
    function<void(int, int)> btrk = [&](int i, int cnt) {
        if (i == q + 1 && cnt == n) {
            int prd = 1;
            for (int s: s) prd *= s;
            ans = max(ans, prd);
            return;
        } else if (i == q + 1 || cnt == n) {
            return;
        }

        for (int j = 0; j < n; j++) {
            if (sel[j]) continue;
            s[i] += x[j];
            sel[j] = true;
            btrk(i, cnt + 1);
            btrk(i + 1, cnt + 1);
            s[i] -= x[j];
            sel[j] = false;
        }
    };

    btrk(0, 0);
    cout << ans << '\n';
}