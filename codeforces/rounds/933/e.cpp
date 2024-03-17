#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m, k, d; cin >> n >> m >> k >> d;
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        vector<long long> minc(n), cst(m);
        for (int i = 0; i < n; i++) {
            deque<int> dq;
            cst[0] = a[i][0] + 1;
            dq.push_back(0);
            for (int j = 1; j < m; j++) {
                cst[j] = a[i][j] + 1 + cst[dq.front()];
                while (!dq.empty() && cst[dq.back()] >= cst[j]) dq.pop_back();
                dq.push_back(j);
                if (dq.front() < j - d) dq.pop_front();
            }
            minc[i] = cst[m - 1];
        }

        long long sum = 0, ans = 0;
        for (int i = 0; i < k; i++) sum += minc[i];
        ans = sum;
        for (int i = k; i < n; i++) {
            sum += minc[i] - minc[i - k];
            ans = min(ans, sum);
        }
        cout << ans << '\n';
    }
}