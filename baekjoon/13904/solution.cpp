#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    vector<pi> dw(n);
    for (auto &[d, w]: dw) cin >> d >> w;
    sort(dw.begin(), dw.end(), greater<pi>());

    priority_queue<int> pq;
    int idx = 0, ans = 0;
    for (int i = 1000; i; i--) {
        while (idx < n && dw[idx].first == i) pq.push(dw[idx++].second);
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << '\n';
}