#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> lrx(m);
    for (auto &[l, r, x]: lrx) cin >> l >> r >> x;
    sort(lrx.begin(), lrx.end());
    priority_queue<pair<int, int>> pq;
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        while (!pq.empty() && pq.top().second < i) pq.pop();
        while (idx < m && get<0>(lrx[idx]) == i) {
            auto [l, r, x] = lrx[idx++];
            pq.emplace(x - l, r);
        }
        cout << (pq.empty() ? 0 : pq.top().first + i) << ' ';
    }
    cout << '\n';
}