#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<pair<int, int>> ab(n);
    for (int i = 0; i < n; i++) cin >> ab[i].first >> ab[i].second;
    sort(ab.begin(), ab.end());

    int l, p; cin >> l >> p;
    priority_queue<int> pq;
    int i = 0;
    while (p < l) {
        while (ab[i].first <= p) pq.push(ab[i++].second);
        if (pq.empty()) break;
        p += pq.top();
        pq.pop();
    }

    if (p < l) cout << -1 << '\n';
    else cout << i - pq.size() << '\n';
}