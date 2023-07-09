#include <iostream>

using namespace std;

const int mod = 1000000000;

int num[100][10];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    num[0][0] = 0;
    for (int i = 1; i < 10; i++) num[0][i] = 1;
    for (int i = 1; i < n; i++) {
        num[i][0] = num[i - 1][1] % mod;
        for (int j = 1; j < 9; j++) num[i][j] = (num[i - 1][j - 1] + num[i - 1][j + 1]) % mod;
        num[i][9] = num[i - 1][8] % mod;
    }
    int ans = 0;
    for (int i = 0; i < 10; i++) ans = (ans + num[n - 1][i]) % mod;
    cout << ans << '\n';
}