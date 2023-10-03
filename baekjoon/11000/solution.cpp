#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

pi crs[200000];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> crs[i].first >> crs[i].second;
    sort(crs, crs + n);
    priority_queue<int, vector<int>, greater<int>> pq;
    int maxc = 0;
    for (int i = 0; i < n; i++) {
        auto [s, e] = crs[i];
        while (!pq.empty() && pq.top() <= s) pq.pop();
        pq.push(e);
        maxc = max(maxc, int(pq.size()));
    }
    cout << maxc << '\n';
}