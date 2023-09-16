#include <bits/stdc++.h>
using namespace std;
const int inf = 123456789;

int cost[3][1000];
int minc[3][3][1000];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> cost[0][i] >> cost[1][i] >> cost[2][i];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            minc[i][j][0] = inf;
    for (int s = 0; s < 3; s++) minc[s][s][0] = cost[s][0];
    for (int i = 1; i < n; i++) {
        for (int s = 0; s < 3; s++) {
            minc[s][0][i] = cost[0][i] + min(minc[s][1][i - 1], minc[s][2][i - 1]);
            minc[s][1][i] = cost[1][i] + min(minc[s][0][i - 1], minc[s][2][i - 1]);
            minc[s][2][i] = cost[2][i] + min(minc[s][0][i - 1], minc[s][1][i - 1]);
        }
    }
    int ans = inf;
    for (int s = 0; s < 3; s++) {
        for (int c = 0; c < 3; c++) {
            if (s == c) continue;
            ans = min(ans, minc[s][c][n - 1]);
        }
    }
    cout << ans << '\n';
}