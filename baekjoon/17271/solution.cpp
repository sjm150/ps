#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> cnt(n + 1);
    fill(cnt.begin(), cnt.begin() + m, 1);
    for (int i = m; i <= n; i++) cnt[i] = (cnt[i - 1] + cnt[i - m]) % mod;
    cout << cnt[n] << '\n';
}