#include <bits/stdc++.h>
using namespace std;

int score[2][100000];
int sum[2][100000];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> score[0][i];
        for (int i = 0; i < n; i++) cin >> score[1][i];
        sum[0][0] = score[0][0];
        sum[1][0] = score[1][0];
        sum[0][1] = sum[1][0] + score[0][1];
        sum[1][1] = sum[0][0] + score[1][1];
        for (int i = 2; i < n; i++) {
            sum[0][i] = max(sum[1][i - 1], max(sum[0][i - 2], sum[1][i - 2])) + score[0][i];
            sum[1][i] = max(sum[0][i - 1], max(sum[0][i - 2], sum[1][i - 2])) + score[1][i];
        }
        cout << max(sum[0][n - 1], sum[1][n - 1]) << '\n';
    }
}