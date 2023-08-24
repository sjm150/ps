#include <bits/stdc++.h>
using namespace std;
const int mod = 15746;

int cnt[1000001];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    cnt[0] = cnt[1] = 1;
    for (int i = 2; i <= n; i++) {
        cnt[i] = cnt[i - 1] + cnt[i - 2];
        if (cnt[i] >= mod) cnt[i] -= mod;
    }
    cout << cnt[n] << '\n';
}