#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    function<int(int, int)> e = [&](int n, int k) {
        if (k == 1 || n == 0) return n;
        int &cnt = dp[n][k];
        if (cnt) return cnt;
        cnt = 1e9;
        for (int i = 1; i <= n; i++) cnt = min(cnt, 1 + max(e(i - 1, k - 1), e(n - i, k)));
        return cnt;
    };
    cout << e(n, k) << '\n';
}