#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c[201][201];
ll comb(int n, int r) {
    ll& cache = c[n][r];
    if (cache > 0) return cache;
    if (r == 0) return cache = 1;
    else return cache = comb(n - 1, r - 1) * n / r;
}

string ans;

bool solve(int n, int m, int k) {
    int i;
    for (int i = 0; i <= n; i++) {
        ll c = comb(m - 1 + i, i);
        if (k <= c) {
            for (int j = 0; j < n - i; j++) ans += 'a';
            ans += 'z';
            if (k == c) {
                for (int j = 0; j < m - 1; j++) ans += 'z';
                for (int j = 0; j < i; j++) ans += 'a';
                return true;
            } else {
                return solve(i, m - 1, k);
            }
        }
        k -= c;
    }
    return false;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    if (solve(n, m, k)) cout << ans << '\n';
    else cout << -1 << '\n';
}