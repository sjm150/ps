#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n, d; cin >> n >> d;
        vector<int> s(n), e(n), ss, es;
        int z, a, c, r; cin >> z >> a >> c >> r;
        s[0] = e[0] = z;
        for (int i = 1; i < n; i++) s[i] = e[i] = (s[i - 1] * a + c) % r;

        cin >> z >> a >> c >> r;
        for (int i = 1; i < n; i++) {
            z = (z * a + c) % r;
            s[i] = min(s[i], s[z % i]);
            e[i] = max(e[i], e[z % i]);
            if (e[i] - s[i] <= d) {
                ss.push_back(s[i]);
                es.push_back(e[i]);
            }
        }
        sort(ss.begin(), ss.end());
        sort(es.begin(), es.end());

        int cnt = 1, ans = 1;
        auto si = ss.begin();
        for (auto ei = es.begin(); ei != es.end(); ei++) {
            cnt++;
            for (; si != ss.end() && *ei - *si > d; si++) cnt--;
            ans = max(ans, cnt);
        }
        cout << "Case #" << tt << ": " << ans << '\n';
    }
}