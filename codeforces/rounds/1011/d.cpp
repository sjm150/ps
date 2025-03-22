#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    typedef long long ll;
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> d(n);
        for (int &d: d) cin >> d;
        int r = 0;
        ll ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = n - 1; i >= 0; i--) {
            if (r < k) {
                r++;
                if (!pq.empty() && pq.top() < d[i]) {
                    ans += d[i] - pq.top();
                    pq.pop();
                    pq.push(d[i]);
                }
            } else {
                ans += d[i];
                pq.push(d[i]);
                r -= k;
            }
        }
        cout << ans << '\n';
    }
}