#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;
 
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<vector<int>> a(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                cin >> a[i][j];
            }
        }
 
        vector<vector<int>> dp(n + 1);
        dp[0].emplace_back(0);
        for (int i = 1; i <= n; i++) {
            priority_queue<int, vector<int>, greater<int>> pq;
            priority_queue<ti> nq;
            pq.push(a[1][i]);
            for (int x: dp[i - 1]) pq.push(x);
            if (pq.size() > k) pq.pop();
            for (int j = 0; j < i - 1; j++) nq.emplace(dp[j][0] + a[j + 2][i], j, 0);

            while (!nq.empty() && (pq.size() < k || get<0>(nq.top()) > pq.top())) {
                auto [v, j, idx] = nq.top(); nq.pop();
                if (idx + 1 < dp[j].size()) nq.emplace(dp[j][idx + 1] + a[j + 2][i], j, idx + 1);
                pq.push(v);
                if (pq.size() > k) pq.pop();
            }

            dp[i].resize(pq.size());
            for (int j = pq.size() - 1; j >= 0; j--) {
                dp[i][j] = pq.top();
                pq.pop();
            }
        }

        for (int x: dp[n]) cout << x << ' ';
        cout << '\n';
    }
}