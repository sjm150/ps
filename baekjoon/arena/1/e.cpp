#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

ll pow2(int x) {
    int ret = 1;
    while (x--) {
        ret *= 2;
        if (ret >= mod) ret -= mod;
    }
    return ret;
}

int c[100000];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        c[a % k]++;
    }
    ll cnt = c[0] + 1;
    if (k % 2 == 0) cnt = cnt * (c[k / 2] + 1) % mod;
    for (int i = 1; i <= (k - 1) / 2; i++) cnt = cnt * (pow2(c[i]) + pow2(c[k - i]) - 1) % mod;
    cout << (cnt - n - 1 + mod) % mod << '\n';
}