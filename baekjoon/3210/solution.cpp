#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int, int>> ca(n);
    for (auto &[c, a]: ca) cin >> c >> a;
    reverse(ca.begin(), ca.end());

    long long ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        auto [c, a] = ca[i];
        ans += a;
        pq.push(c - a);
        if (pq.size() * 2 > i + 1) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << '\n';
}