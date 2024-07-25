#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, a, b, m; cin >> n >> a >> b >> m;
    a--, m--;

    vector<int> pst(n), stu(n);
    iota(pst.begin(), pst.end(), 0);
    iota(stu.begin(), stu.end(), 0);
    int cnt = 0, cur = 0, mx = 0;
    if (abs(pst[0] - pst[a]) <= b) cnt = cur = mx = 1;

    while (m--) {
        vector<int> s(n);
        for (int &s: s) cin >> s;
        for (int &s: s) {
            int x; cin >> x;
            s -= x;
        }

        auto swp = [&](int i, int j) {
            swap(pst[i], pst[j]);
            swap(stu[pst[i]], stu[pst[j]]);
            s[i] += 2;
            s[j] -= 2;
        };

        for (int i = 0; i < n - 1; i++) {
            int a = stu[i], b = stu[i + 1];
            if (s[a] >= 0 && s[b] >= 0) {
                if (s[b] - s[a] >= 2) swp(a, b);
            } else if (s[b] >= 0) {
                swp(a, b);
            } else if (s[a] < 0) {
                if (s[b] - s[a] >= 4) swp(a, b);
            }
        }

        if (abs(pst[0] - pst[a]) <= b) {
            cnt++;
            cur++;
            mx = max(mx, cur);
        } else {
            cur = 0;
        }
    }

    cout << cnt << ' ' << mx << '\n';
}