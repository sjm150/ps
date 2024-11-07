#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<pair<int, int>> ab(m);
        for (auto &[a, b]: ab) cin >> a >> b;
        sort(ab.begin(), ab.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        int j = 0, cnt = 0;
        for (int i = 1; i <= n; i++) {
            while (j < m && ab[j].first <= i) pq.push(ab[j++].second);
            while (!pq.empty() && pq.top() < i) pq.pop();
            if (!pq.empty()) {
                cnt++;
                pq.pop();
            }
        }
        cout << cnt << '\n';
    }
}