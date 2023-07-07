#include <iostream>

using namespace std;

int n;
int cost[3][1000];
int dp[3][1000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> cost[0][i] >> cost[1][i] >> cost[2][i];
    dp[0][0] = cost[0][0];
    dp[1][0] = cost[1][0];
    dp[2][0] = cost[2][0];
    for (int i = 1; i < n; i++) {
        dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + cost[0][i];
        dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + cost[1][i];
        dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + cost[2][i];
    }
    cout << min(dp[0][n - 1], min(dp[1][n - 1], dp[2][n - 1])) << '\n';
}