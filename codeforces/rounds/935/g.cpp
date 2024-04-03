#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> ti;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, d; cin >> n >> d;
        vector<int> k(n), s(n);
        for (int i = 0; i < n; i++) cin >> k[i] >> s[i];

        vector<int> mxk(n);
        mxk[n - 1] = k[n - 1];
        for (int i = n - 2; i >= 0; i--) mxk[i] = max(k[i], mxk[i + 1]);

        priority_queue<ti> pq;
        priority_queue<ti, vector<ti>, greater<ti>> eq;
        int tm = 0, st = 0;
        for (; tm < d && st < n; tm++) {
            if (!pq.empty() && mxk[st] < get<0>(pq.top())) {
                auto [kk, tt, ns] = pq.top(); pq.pop();
                eq.emplace(tm - ns, kk, ns);
            } else {
                eq.emplace(tm + s[st], k[st], -s[st]);
                st++;
            }
            while (!eq.empty() && get<0>(eq.top()) <= tm) {
                auto [tt, kk, ns] = eq.top(); eq.pop();
                pq.emplace(kk, -tm, ns);
            }
        }

        if (st == n) cout << tm << '\n';
        else cout << -1 << '\n';
    }
}