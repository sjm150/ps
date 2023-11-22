#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<pi> pairs(n);
    for (int i = 0; i < n; i++) cin >> pairs[i].first >> pairs[i].second;
    int d; cin >> d;
    vector<pi> es;
    for (auto [h, o]: pairs) {
        if (abs(h - o) > d) continue;
        if (h > o) es.emplace_back(h, o);
        else es.emplace_back(o, h);
    }
    sort(es.begin(), es.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    int maxs = 0;
    for (auto [e, s]: es) {
        while (!pq.empty() && pq.top() < e - d) pq.pop();
        pq.push(s);
        if (maxs < pq.size()) maxs = pq.size();
    }
    cout << maxs << '\n';
}