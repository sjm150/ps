#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 3;

int cnt[1000][1001];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i < n; i++) {
        cnt[i][0] = 1;
        cnt[i][1] = i;
    }
    for (int i = 3; i < n; i++) {
        for (int j = 2; j <= (i + 1) / 2; j++) {
            cnt[i][j] = (cnt[i - 2][j - 1] + cnt[i - 1][j]) % mod;
        }
    }
    cout << (cnt[n - 3][k - 1] + cnt[n - 1][k]) % mod << '\n';
}