#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int &a: a) cin >> a;
        sort(a.begin(), a.end());

        int sz = k * 2;
        vector<bool> occ(sz, false);
        bool poss = true;
        for (int a: a) {
            if (occ[(a + k) % sz]) {
                poss = false;
                break;
            }
            occ[a % sz] = true;
        }
        if (!poss) {
            cout << -1 << '\n';
            continue;
        }

        queue<int> q;
        int mx = *max_element(a.begin(), a.end());
        for (int i = 1; i < k; i++) {
            if (occ[(mx + i) % sz]) q.push(mx + i);
        }
        bool done = false;
        for (int i = 0; i < sz; i++) {
            if (occ[(mx + i + k) % sz]) q.push(mx + i + k);
            while (!q.empty() && q.front() == mx + i) q.pop();
            if (q.empty()) {
                cout << mx + i << '\n';
                done = true;
                break;
            }
        }
        if (!done) cout << -1 << '\n';
    }
}