#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int k, n; cin >> k >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll l = a[0];
    for (int i = 1; i < n; i++) {
        ll g = gcd(l, a[i]);
        l = l / g * a[i];
    }
    cout << l - k << '\n';
}