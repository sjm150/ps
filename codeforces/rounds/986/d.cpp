#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> q(n), k(n), j(n);
        auto init = [&](vector<int> &p) {
            for (int &p: p) cin >> p;
        };
        init(q);
        init(k);
        init(j);

        vector<pair<int, char>> pre(n, {-1, ' '});
        int qi = 0, ki = 0, ji = 0;
        for (int i = 1; i < n; i++) {
            if (q[qi] > q[i]) pre[i] = {qi, 'q'};
            else if (k[ki] > k[i]) pre[i] = {ki, 'k'};
            else if (j[ji] > j[i]) pre[i] = {ji, 'j'};
            if (pre[i].first < 0) continue;
            if (q[qi] < q[i]) qi = i;
            if (k[ki] < k[i]) ki = i;
            if (j[ji] < j[i]) ji = i;
        }

        function<void(int, int)> prnt = [&](int cnt, int cur) {
            if (cur == 0) {
                cout << cnt << '\n';
            } else {
                prnt(cnt + 1, pre[cur].first);
                cout << pre[cur].second << ' ' << cur + 1 << endl;
            }
        };
        if (pre[n - 1].first < 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            prnt(0, n - 1);
        }
    }
}