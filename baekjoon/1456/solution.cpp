#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool nprime[10000001];
vector<ll> primes;

void init(int n) {
    nprime[0] = nprime[1] = true;
    for (int i = 2; i <= n; i++) {
        if (nprime[i]) continue;
        primes.push_back(i);
        for (ll j = ll(i) * i; j <= n; j += i) nprime[j] = true;
    }
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll a, b; cin >> a >> b;
    init(sqrt(b) + 1);
    int cnt = 0;
    for (int p: primes) {
        for (ll i = p; i <= b / p; i *= p) {
            if (i * p >= a) cnt++;
        }
    }
    cout << cnt << '\n';
}