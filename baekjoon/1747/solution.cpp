#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MX = 1003001;

bool ispal(ll x) {
    ll l = 1, r = 1;
    while (x / l / 10) l *= 10;
    while (l > r) {
        if (x / l % 10 != x / r % 10) return false;
        l /= 10;
        r *= 10;
    }
    return true;
}

int solve(int n) {
    vector<bool> prm(MX, true);
    for (ll i = 2; i < MX; i++) {
        if (!prm[i]) continue;
        if (i >= n && ispal(i)) return i;
        for (ll j = i * i; j < MX; j += i) prm[j] = false;
    }
    return MX;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    cout << solve(n) << '\n';
}