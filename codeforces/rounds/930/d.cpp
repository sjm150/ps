#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pil;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        vector<pil> lsum, rsum;
        lsum.emplace_back(-1, 0);
        rsum.emplace_back(-1, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] == '>') lsum.emplace_back(i, i + 1 + lsum.back().second);
            else rsum.emplace_back(i, i + 1 + rsum.back().second);
        }
        rsum.emplace_back(n, rsum.back().second);

        for (int i = 0; i < n; i++) {
            int lidx = lower_bound(lsum.begin(), lsum.end(), pil(i, 0)) - lsum.begin();
            int ridx = lower_bound(rsum.begin(), rsum.end(), pil(i, 0)) - rsum.begin();
            if (s[i] == '<') lidx--;

            int lcnt = lidx, rcnt = rsum.size() - 1 - ridx;
            ll ans;
            if (s[i] == '>') {
                if (lcnt > rcnt) lcnt = rcnt + 1;
                else rcnt = lcnt;
                ans = 2 * ((rsum[ridx + rcnt - 1].second - rsum[ridx - 1].second) -
                    (lsum[lidx].second - lsum[lidx - lcnt].second)) + lsum[lidx].first + 1;
                if (lcnt > rcnt) ans += n + 1;
            } else {
                if (rcnt > lcnt) rcnt = lcnt + 1;
                else lcnt = rcnt;
                ans = 2 * ((rsum[ridx + rcnt - 1].second - rsum[ridx - 1].second) -
                    (lsum[lidx].second - lsum[lidx - lcnt].second)) - rsum[ridx].first - 1;
                if (rcnt == lcnt) ans += n + 1;
            }
            cout << ans << ' ';
        }
        cout << '\n';
    }
}