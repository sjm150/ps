#include <iostream>

using namespace std;

int num[500][500];
int sum[500][500];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> num[i][j];
        }
    }
    sum[0][0] = num[0][0];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= i; j++) {
            sum[i + 1][j] = max(sum[i + 1][j], sum[i][j] + num[i + 1][j]);
            sum[i + 1][j + 1] = max(sum[i + 1][j + 1], sum[i][j] + num[i + 1][j + 1]);
        }
    }
    int max_sum = 0;
    for (int j = 0; j < n; j++) {
        max_sum = max(max_sum, sum[n - 1][j]);
    }
    cout << max_sum << '\n';
}